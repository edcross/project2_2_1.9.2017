
#include <cstdlib>
#include <iostream>
//#include <bits/basic_string.h>
#include <fstream>
//#include <bits/stl_vector.h>
#include <vector>

#include <map>
#include <iosfwd>
//#include <bits/stringfwd.h>
//#include <bits/stl_map.h>
#include <iterator>
//#include <bits/stl_vector.h>
//#include <bits/stl_map.h>
#include <string>
#include <boost/lexical_cast.hpp>
//#include <bits/stl_vector.h>
#include "ImageTags.h"
#include <utility>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include <iostream> // std::cout, std::fixed
#include <iomanip>

#include "fileMethods/fileMethods.cpp"

using namespace std;

void trim(string &s); //line added

std::vector<std::string> split(std::string s, char delim)
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    return tokens;
}

int main(int argc, char **argv)
{
    //string troubleshooting = "";
    std::string li;
    std::ifstream arquitectura("arquit.txt");
    while (getline(arquitectura, li))
    {                         //while superior
        int seqLength = 9216; //line added

        ImageTags temporalTag(""); //ImageTags("")
        std::vector<ImageTags> imageSeq(seqLength, temporalTag);
        int ite = 0; //line added

        for (int numeroSeq = 1; numeroSeq <= 3; ++numeroSeq)
        { //line added

            std::string descriptorFolderPath = "/home/ed/Documents/VidriloTags/Sequence" + boost::lexical_cast<std::string>(numeroSeq) + "/Vidrilo_Sequence" + boost::lexical_cast<std::string>(numeroSeq) + li + "/";

            std::string imageListPath = "/home/ed/Dropbox/shared_ED/categorias/Sq" + boost::lexical_cast<std::string>(numeroSeq) + ".txt";

            std::string line;
            std::ifstream imageList(imageListPath.c_str());

            if (imageList.is_open())
            {
                int i = 0;
                while (getline(imageList, line))
                {

                    std::vector<std::string> splitLine = split(line, '\t');
                    string temp = splitLine.at(0);
                    trim(temp);

                    //std::cout << splitLine.at(0) << "\n";
                    //std::string descriptorFilePath = descriptorFolderPath + splitLine.at(0) + ".txt";
                    std::string descriptorFilePath = descriptorFolderPath + temp + ".txt";
                    std::ifstream descriptor(descriptorFilePath.c_str());
                    std::string tagLine;
                    if (descriptor.is_open())
                    {
                        //imageSeq.at(ite).init(splitLine.at(0));
                        imageSeq.at(ite).init(temp);
                        imageSeq.at(ite).setCategory(splitLine.at(1));

                        imageSeq.at(ite).setCategoryNumber(boost::lexical_cast<int>(splitLine.at(2)));
                        while (getline(descriptor, tagLine))
                        {

                            imageSeq.at(ite).addTag(tagLine);
                        }
                    }
                    else
                    {
                        std::cout << "Descriptor no abierto" << std::endl;
                        cout << li << "-" << temp << "\n";
                    }
                    descriptor.close();

                    ++ite;

                } //end while image list
                imageList.close();
            }
            else
                std::cout << "No se abrio la lista de los txt" << std::endl;

        } //en for  superior

        std::vector<std::string> keyList = imageSeq.at(0).getKeysVector();
        std::stringstream fileKeyList;
        std::stringstream csvFile;

        csvFile << "Category";

        for (std::vector<std::string>::iterator it = keyList.begin(); it != keyList.end(); ++it)
        {

            fileKeyList << (*it) << "\n";
            //std::cout << (*it) << std::endl;

            csvFile << "," << (*it);
        }

        csvFile << "\n";

        int i = 0;
        for (std::vector<ImageTags>::iterator it = imageSeq.begin(); it != imageSeq.end(); ++it)
        {

            int j = 0;

            csvFile << (*it).getClassNumber();
            for (std::vector<std::string>::iterator it2 = keyList.begin(); it2 != keyList.end(); ++it2)
            {

                csvFile << "," << std::fixed << std::setprecision(8) << (*it).tags.at((*it2));
            }

            ++i;
            csvFile << "\n";
        }
        string namefile = "VidriloSEQ_1_3_" + li + "_CSV";
        fileMethods::saveData(namefile, csvFile.str(), false);
        std::cout << namefile << " was saved"
                  << "\n";
    } //end while superior
      //fileMethods::saveData("troubleshooting", troubleshooting, false);
    return 0;
}

void trim(string &s)
{
    while (s.compare(0, 1, " ") == 0)
        s.erase(s.begin()); // remove leading whitespaces
    while (s.size() > 0 && s.compare(s.size() - 1, 1, " ") == 0)
        s.erase(s.end() - 1); // remove trailing whitespaces
}
