/* 
 * File:   Node.cpp
 * Author: jcarlos2289
 * 
 * Created on 24 de octubre de 2016, 19:15
 */

#include "Node.h"


using namespace std;

//tags de Node pasa a ser tags_ind

/*std::map<std::string, float> tags_ind;
std::vector<ImageTags> images;
ImageTags representative("test");
vector<std::vector<double> > distances;
vector<double> sumDistances;
std::map<std::string, float> histoMean;
std::map<std::string, float> histoVariance;
std::map<std::string, float> histoStanDev;
string nodeName = "";
float nodeVariance;*/

Node::Node() {
//    histoMean.clear();
//    histoVariance.clear();
//    histoStanDev .clear();
//    nodeVariance = 0;
//
//    distances.clear();
//    sumDistances.clear();
//    images.clear();
    
}

//Node::Node(const Node& orig) {
//}
//
//Node::~Node() {
//}
//
//int Node::getSize() {
//    return images.size();
//}
//
//void Node::printMeanCoords() {
//    double xmean = 0.0, ymean = 0.0;
//    int cont = 0;
//
//    for (int i = 0; i < images.size(); i++) {
//        if (images.at(i).xcoord != -1) {
//            xmean += images.at(i).xcoord;
//            ymean += images.at(i).ycoord;
//            cont++;
//        }
//    }
//    std::stringstream ss;
//
//    ss << xmean / cont << " " << ymean / cont << endl;
//    cout << ss.str() << endl;
//}
//
//void Node::printCoords() {
//    /*if (representative.xcoord != -1)
//       cout <<"Corrdenadas del Prepresentativo" << endl; //System.out.println(representative.xcoord + " " + representative.ycoord);
//    else {
//        for (int i = 0; i < images.size(); i++) {
//            if (images.at(i).xcoord != -1) {
//                cout<< "Coordenadas de todo" << endl;//ystem.out.println(images.get(i).xcoord + " " + images.get(i).ycoord);
//                break;
//            }
//        }
//    }*/
//}
//
//void Node::add(ImageTags img) {
//    double minDist = std::numeric_limits<double>::max(), auxDist, auxSumDist = 0.0;
//    int minImg = 0;
//    double auxx, auxy;
//    std::vector<double> di;
//    std::set<std::string>::iterator iterator;
//    std::set<std::string> keys;
//    std::string elem;
//
//
//    if (images.size() == 0) { // When the node is created, only one image is present
//        images.push_back(img);
//        representative.init(img.imageName);
//        representative.category = img.category;
//        representative.xcoord = img.xcoord;
//        representative.ycoord = img.ycoord;
//
//        keys = img.getKeys();
//        iterator = keys.begin();
//
//        while (iterator != keys.end()) {
//            elem = *iterator++;
//
//            histoMean.insert(std::pair<std::string, float>(elem, img.tags.at(elem)));
//            // number of nodes n = 1 in the begining
//            histoVariance.insert(std::pair<std::string, float>(elem, pow(img.tags.at(elem) - histoMean.at(elem), 2)));
//            histoStanDev.insert(std::pair<std::string, float>(elem, sqrt(histoVariance.at(elem))));
//        }
//    } else {// When the node have some images inside, without weights
//        images.push_back(img);
//        int n = images.size();
//        double xmedian [images.size()], ymedian [images.size()];
//        if (images.size() < std::numeric_limits<double>::max()/*2 * weights.length*/) { // only when we don't need to use weights
//
//            keys = img.getKeys();
//            iterator = keys.begin();
//
//            while (iterator != keys.end()) {
//                elem = *iterator++;
//                if (histoMean.at(elem) != NULL) { // the tag is present// in the hash
//                    histoMean[elem] = ((histoMean.at(elem) * (n - 1) + img.tags.at(elem)) / n);
//                } else {
//                    // The actual tag don't exits in the hash, so we add
//                    histoMean.insert(std::map<std::string, float>::value_type(elem, img.tags.at(elem) / n));
//                }
//            }
//            for (int i = 0; i < n; i++) {
//                xmedian[i] = images.at(i).xcoord;
//                ymedian[i] = images.at(i).ycoord;
//            }
//            //HashMap g = New HashMap<String, ArrayList<Double>>;
//            //  JC
//            // --------------------------------------------------------------------
//            // calcular la varianza sin los pesos
//            keys = images.at(0).getKeys();
//            iterator = keys.begin();
//            while (iterator != keys.end()) {
//                elem = *iterator++; // The first element is added to reset all the elements in the hash
//                histoVariance[elem] = (pow(images.at(0).tags.at(elem) - histoMean.at(elem), 2) / images.size());
//                histoStanDev[elem] = (sqrt(histoVariance.at(elem)));
//            }
//
//            ImageTags imagesAux;
//            // int imgSize = images.size();
//            for (int i = 1; i < images.size(); ++i) {
//                imagesAux = images.at(i);
//                std::set<std::string> keyList = imagesAux.getKeys();
//                std::set<std::string>::iterator keyAux = keyList.begin();
//                while (keyAux != keyList.end()) {
//                    std::string key = *keyAux++;
//                    if (histoVariance.at(key) != NULL) { // the actual tag is present in the hashMap
//                        histoVariance[key] = (histoVariance.at(key) + pow(imagesAux.tags.at(key) - histoMean.at(key), 2) / (images.size()));
//                    } else // the tag isn't in the hashMap
//                        histoVariance.insert(std::map<std::string, float>::value_type(key, (pow(imagesAux.tags.at(key) - histoMean.at(key), 2) / (images.size()))));
//                    histoStanDev[key] = (sqrt(histoVariance.at(key)));
//                }
//            }
//
//        } else {
//        }
//
//        std::sort(xmedian, xmedian + (sizeof (xmedian)));
//        std::sort(ymedian, ymedian + (sizeof (ymedian)));
//        // Arrays.sort(ymedian);
//        representative.xcoord = xmedian[sizeof (xmedian) / 2];
//        representative.ycoord = ymedian[sizeof (ymedian) / 2];
//        minDist = std::numeric_limits<double>::max();
//        auxx = -1;
//        auxy = -1;
//
//        for (std::vector<ImageTags>::iterator it = images.begin(); it != images.end(); ++it) {
//            auxDist = hypot((*it).xcoord - representative.xcoord, (*it).ycoord - representative.ycoord);
//            if (auxDist < minDist) {
//                minDist = auxDist;
//                auxx = (*it).xcoord;
//                auxy = (*it).ycoord;
//            }
//        }
//        representative.xcoord = auxx;
//        representative.ycoord = auxy;
//
//    }
//    nodeVariance = 0;
//
//    std::map<std::string, float>::const_iterator itr;
//    for (itr = histoVariance.begin(); itr != histoVariance.end(); ++itr) {
//        nodeVariance += (*itr).second;
//    }
//
//    representative.tags = histoMean;
//    //histoMean.putAll(representative.tags);
//}
//
//double Node::distance(ImageTags t1, ImageTags t2) {
//    float dist = 0.0f;
//    std::string elem;
//    std::set<std::string> hs1;
//    std::vector<std::string> hs2;
//    //std::set<std::string> aux;
//
//    std::set<std::string>::iterator iterator;
//
//    //aux = t2.getKeys();
//    hs2 = t2.getKeysVector();
//    hs1 = t1.getKeys();
//
//
//
//
//    iterator = hs1.begin();
//    while (iterator != hs1.end()) {
//        elem = *iterator++;
//        dist += pow(t1.tags.at(elem) - t2.tags.at(elem), 2.0);
//        for (int i = 0; i < hs2.size(); i++) {
//            // this is for the situation
//            // that in the second tags
//            // there is a tag not
//            // present in the first
//
//            if ((hs2.at(i) != " ")&& (hs2.at(i) == elem)) {
//                hs2.at(i) = " ";
//                break;
//            }
//        }
//    }
//
//    for (int i = 0; i < hs2.size(); i++) {
//        if (hs2.at(i) != " ")
//            dist += pow(t2.tags.at(hs2[i]), 2.0);
//    }
//
//    return sqrt(dist);
//}
//
//double Node::distance(std::map<std::string, float> histo, ImageTags t2) {
//
//    float dist = 0.0f;
//    std::string elem;
//    std::set<std::string> hs1;
//    std::set<std::string>::iterator iterator;
//
//    std::map<std::string, float> w ;
//    float wSum = 0;
//    
//   
//    std::map<std::string, float>::const_iterator itr;
//    for (itr = histoStanDev.begin(); itr != histoStanDev.end(); ++itr) {
//        w.insert(std::map<std::string, float>::value_type((*itr).first, 1 - 2 * (*itr).second));
//        wSum += w.at((*itr).first);
//    }
//        
//    /*
//
//    hs1 = histo.;
//    iterator = hs1.iterator();
//    */
//    std::map<std::string, float>::const_iterator hisIt;
//    for (hisIt = histoStanDev.begin(); hisIt != histoStanDev.end(); ++hisIt) {
//        elem = (*hisIt).first;
//        if (t2.exists(elem)) {
//            dist += pow(histo.at(elem) - t2.tags.at(elem), 2.0) * w.at(elem);
//        }
//   }
//         
//    return sqrt(dist / wSum);
//}