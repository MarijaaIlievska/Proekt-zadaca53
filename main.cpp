//Marija Ilievska INKI870 ZADACA BR.53
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Profil // kreiranje na struktura profil i elementi

{

int IDbroj=0; 

std::string Nickname;

float  Nivo;

Profil(int ID, const string& Nickname)

: IDbroj(IDbroj), Nickname(Nickname), Nivo(Nivo) // Inicijaliziranje na clenovite
{

}
//operator< za funkcii kako std(std-ovozmozuva sporedba na profilite za da gi sortira redosledno)
bool operator<(const Profil& p) const

{
//go vrakja imeto sortirano redosledno
return Nickname < p.Nickname; 

}

};

// sortiranje na pokazuvacite
struct SortProfilePointers

{
bool operator()(const Profil* lhs, const Profil* rhs) const

{

return *lhs < *rhs;

}

};

int main()

{
//definiranje na vektor i kreiranje na profilite
vector<Profil*> Profiles;

Profiles.push_back(new Profil(4, "Ivona")); 

Profiles.push_back(new Profil(1, "Lara"));

Profiles.push_back(new Profil(5, "Stefani"));

Profiles.push_back(new Profil(2, "Aleksandra"));

Profiles.push_back(new Profil(3, "Maja"));

std::sort(Profiles.begin(), Profiles.end(), SortProfilePointers()); //sporeduvac

for(const auto* p: Profiles)
cout << p->IDbroj << ": " << p->Nickname << '\n';



ofstream outFile ("INKI870MarijaIlievska.txt");
for(const auto* p: Profiles ) outFile<<p<<endl;

for(auto* p: Profiles)
delete p;
}