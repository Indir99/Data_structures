#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<fstream>

class Station{
  public:
    std::string name;
    std::string StationID;
    std::string lattitude;
    std::string longitude;
    std::string Elevation;
    class years;
    std::vector<years> vec_years;
};

class Station::years{
  public: 
  int year_;
  class mon;
  std::vector<mon> vec_month{12};
};

class Station::years::mon{
  public:
  std::string tmin="N/A";
  std::string tmax="N/A"; 
  //friend class year;
};


//Funkcije koristene u zadatku!
//
void getStations(std::list<Station>&);   //Funkcija pomocu koje smijestamo sve stanice u listu stanica
void getInfomonth(std::list<Station>&); 
void getInfoyear(std::list<Station>&);   //Pomocu date funkcije vrsimo pretrazivanje liste i dolazimo do stanice za koju zelimo citati podatke
void printStations(std::list<Station>&);  //Pomocna funkcija pomocu koje smo testirali ispis stanica i nekih njihovih podataka
void printyear(std::istream&,Station&, int);  //vrsimo ispis podataka za jednu godinu 
void printmonth(std::istream&, Station&, int, int);
void insertdata(std::list<Station>&);   //Funkcija u kojoj unosimo podatke koje zelimo mijeanjti
void insertTemperature(std::istream&,std::list<Station>::iterator, int, int, std::string, std::string); //pomocu ove funkcije vrsimo upis podataka za odg mjesec

int main(int argc, char *argv[])
{
  std::list<Station> base;
  getStations(base);
  while(true){
    int choice;
    std::cout<<std::string(15,'*')<<" Historical temperature information "<<std::string(15,'*')<<std::endl;
    std::cout<<std::string(7,' ')<<" 1. Get information for entire year "<<std::endl;
    std::cout<<std::string(7,' ')<<" 2. Get information for specific month "<<std::endl;
    std::cout<<std::string(7,' ')<<" 3. Insert new historical temperature information"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::string(7,' ')<<" 4. Exit"<<std::endl;
    std::cout<<"Your choice?:";
    std::cin>>choice;
    if(choice==1){
      getInfoyear(base);
    }
    else if(choice==2){
      getInfomonth(base);
    }
    else if(choice==3){
      insertdata(base);
      
    }
    else if(choice==4){
      break;
    }
    std::cout<<std::endl;
  }
  return 0;
}

void getStations(std::list<Station>& base){
  std::string str;
  std::ifstream filename{"stations.csv"};
  filename>>str;
  while(!filename.eof()){
  Station new_station;
  std::string str2;
    filename>>str2;
    auto i=0;
    for(;i<str2.size();i++){
      if(str2.at(i)!=','){
        new_station.StationID.push_back(str2.at(i));
      }
      else{
        break;
      }
  }
    i++;
  for(;i<str2.size();i++){
      if(str2.at(i)!=','){
        new_station.lattitude.push_back(str2.at(i));
      }
      else{
        break;
      }
  }
  i++;
  for(;i<str2.size();i++){
      if(str2.at(i)!=','){
        new_station.longitude.push_back(str2.at(i));
      }
      else{
        break;
      }
  }
  i++;
  for(;i<str2.size();i++){
      if(str2.at(i)!=','){
        new_station.Elevation.push_back(str2.at(i));
      }
      else{
        break;
      }
  }
  i++;
  for(;i<str2.size();i++){
      if(str2.at(i)!=','){
        new_station.name.push_back(str2.at(i));
      }
      else{
        break;
      }
  }
  base.push_back(new_station);
  }
}



void printStations(std::list<Station>& base){
  std::cout<<"Dostupne stanice su: "<<std::endl;
  for(auto i=base.begin();i!=base.end();i++){
    auto temp=*i;
    std::cout<<temp.name<<std::endl;
  }
}


void getInfoyear(std::list<Station>& base){
  std::string station;
  std::cout<<"Enter location where station is placed: ";
  std::cin.ignore();
  std::getline(std::cin,station);
  std::cin.clear();
  if(station=="Banja Luka"){
    station="BanjaLuka";
  }
  Station temp;
  for(auto it=base.begin();it!=base.end();it++){
    temp=*it;
    if(station==temp.name){
      std::cout<<"StationID: "<<temp.StationID<<std::endl;
      std::cout<<"Lattitude: "<<temp.lattitude<<std::endl;
      std::cout<<"Logitude: "<<temp.longitude<<std::endl;
      std::cout<<"Elevation: "<<temp.Elevation<<std::endl;
      std::string file=station+".csv";
      std::ifstream filename{file};
      if(filename.is_open()){
      //  std::cout<<"Uspijedno otvoren: "<<file<<std::endl;
        int year;
        std::cout<<"Enter year: "<<std::endl;
        std::cin>>year;
        if(year<=0){
          std::cout<<"Invalid number, try again!"<<std::endl;
          return;
        }
        std::cout<<std::endl;
      //std::cout<<"Poziv"<<std::endl;
        printyear(filename,temp,year);
        std::cout<<std::endl;
        return;
      }
    }
  }
  std::cout<<"Station does not exist"<<std::endl;
}

void getInfomonth(std::list<Station>& base){
  std::string station;
  std::cout<<"Enter location where station is placed: ";
  std::cin.ignore();
  std::getline(std::cin,station);
  std::cin.clear();
  if(station=="Banja Luka"){
    station="BanjaLuka";
  }
  Station temp;
  for(auto it=base.begin();it!=base.end();it++){
    temp=*it;
    if(station==temp.name){
      std::cout<<"StationID: "<<temp.StationID<<std::endl;
      std::cout<<"Lattitude: "<<temp.lattitude<<std::endl;
      std::cout<<"Logitude: "<<temp.longitude<<std::endl;
      std::cout<<"Elevation: "<<temp.Elevation<<std::endl;
      std::string file=station+".csv";
      std::ifstream filename{file};
      if(filename.is_open()){
       // std::cout<<"Uspijedno otvoren: "<<file<<std::endl;
        int year, month;
        std::cout<<"Enter year: "<<std::endl;
        std::cin>>year;
        if(year<=0){
          std::cout<<"Invalid number, try again!"<<std::endl;
          return;
        }
        std::cout<<"Enter month: "<<std::endl;
        std::cin>>month;
        if(month<=0 || month>12){
          std::cout<<"Inalid number, try again!"<<std::endl;
          return;
        }
        std::cout<<std::endl;
       // std::cout<<"Poziv"<<std::endl;
        printmonth(filename,temp,year,month);
        std::cout<<std::endl;
        return;
      }
    }
  }
  std::cout<<"Station does not exist!"<<std::endl;
}




void printyear(std::istream& filename, Station& station, int year){
  std::string str;
  filename>>str;
  Station::years newq;
  for(auto i=0;i<station.vec_years.size();i++){
    if(year==station.vec_years.at(i).year_){
  std::cout<<"Month"<<std::string(8,' ')<<"Max temp"<<std::string(10,' ')<<"Min temp "<<std::endl;
  std::cout<<"Jan"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(0).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(0).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(0).tmin<<' '<<std::endl;
  std::cout<<"Feb"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(1).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(1).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(1).tmin<<' '<<std::endl;
  std::cout<<"Mar"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(2).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(2).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(2).tmin<<' '<<std::endl;
  std::cout<<"Apr"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(3).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(3).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(3).tmin<<' '<<std::endl;
  std::cout<<"May"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(4).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(4).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(4).tmin<<' '<<std::endl;
  std::cout<<"Jun"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(5).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(5).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(5).tmin<<' '<<std::endl;
  std::cout<<"Jul"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(6).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(6).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(6).tmin<<' '<<std::endl;
  std::cout<<"Aug"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(7).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(7).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(7).tmin<<' '<<std::endl;
  std::cout<<"Sep"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(8).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(8).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(8).tmin<<' '<<std::endl;
  std::cout<<"Oct"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(9).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(9).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(9).tmin<<' '<<std::endl;
  std::cout<<"Nov"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(10).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(10).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(10).tmin<<' '<<std::endl;
  std::cout<<"Dec"<<std::string(10,' ')<<station.vec_years.at(i).vec_month.at(11).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(11).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(11).tmin<<' '<<std::endl;
return;
    }
    }
  while(!filename.eof()){
  char c;
   std::string dummy;
    int yr;
  while(c!=','){
    filename>>c;
    dummy.push_back(c);
  }
  filename>>yr;
  if(year==yr){
    newq.year_=yr;
    filename>>c;
    int month;
    filename>>month;
    std::string tmax,tmin;
    filename>>c;
    filename>>c;
    while(c!=','){
      tmax.push_back(c);
      filename>>c;
    }
    while(c<'A'){
      if(c!=',')
      tmin.push_back(c);
      filename>>c;
    }
    if(tmin.size())
    newq.vec_month.at(month-1).tmin=tmin;
    if(tmax.size())
    newq.vec_month.at(month-1).tmax=tmax;
  }
  else{
  filename>>dummy;
  filename>>c;
  }
  }
  std::cout<<"Month"<<std::string(8,' ')<<"Max temp"<<std::string(10,' ')<<"Min temp "<<std::endl;
  std::cout<<"Jan"<<std::string(10,' ')<<newq.vec_month.at(0).tmax<<std::string(18-newq.vec_month.at(0).tmax.size(),' ')<<newq.vec_month.at(0).tmin<<' '<<std::endl;
  std::cout<<"Feb"<<std::string(10,' ')<<newq.vec_month.at(1).tmax<<std::string(18-newq.vec_month.at(1).tmax.size(),' ')<<newq.vec_month.at(1).tmin<<' '<<std::endl;
  std::cout<<"Mar"<<std::string(10,' ')<<newq.vec_month.at(2).tmax<<std::string(18-newq.vec_month.at(2).tmax.size(),' ')<<newq.vec_month.at(2).tmin<<' '<<std::endl;
  std::cout<<"Apr"<<std::string(10,' ')<<newq.vec_month.at(3).tmax<<std::string(18-newq.vec_month.at(3).tmax.size(),' ')<<newq.vec_month.at(3).tmin<<' '<<std::endl;
  std::cout<<"May"<<std::string(10,' ')<<newq.vec_month.at(4).tmax<<std::string(18-newq.vec_month.at(4).tmax.size(),' ')<<newq.vec_month.at(4).tmin<<' '<<std::endl;
  std::cout<<"Jun"<<std::string(10,' ')<<newq.vec_month.at(5).tmax<<std::string(18-newq.vec_month.at(5).tmax.size(),' ')<<newq.vec_month.at(5).tmin<<' '<<std::endl;
  std::cout<<"Jul"<<std::string(10,' ')<<newq.vec_month.at(6).tmax<<std::string(18-newq.vec_month.at(6).tmax.size(),' ')<<newq.vec_month.at(6).tmin<<' '<<std::endl;
  std::cout<<"Aug"<<std::string(10,' ')<<newq.vec_month.at(7).tmax<<std::string(18-newq.vec_month.at(7).tmax.size(),' ')<<newq.vec_month.at(7).tmin<<' '<<std::endl;
  std::cout<<"Sep"<<std::string(10,' ')<<newq.vec_month.at(8).tmax<<std::string(18-newq.vec_month.at(8).tmax.size(),' ')<<newq.vec_month.at(8).tmin<<' '<<std::endl;
  std::cout<<"Oct"<<std::string(10,' ')<<newq.vec_month.at(9).tmax<<std::string(18-newq.vec_month.at(9).tmax.size(),' ')<<newq.vec_month.at(9).tmin<<' '<<std::endl;
  std::cout<<"Nov"<<std::string(10,' ')<<newq.vec_month.at(10).tmax<<std::string(18-newq.vec_month.at(10).tmax.size(),' ')<<newq.vec_month.at(10).tmin<<' '<<std::endl;
  std::cout<<"Dec"<<std::string(10,' ')<<newq.vec_month.at(11).tmax<<std::string(18-newq.vec_month.at(11).tmax.size(),' ')<<newq.vec_month.at(11).tmin<<' '<<std::endl;
}


void printmonth(std::istream& filename,Station& station,int year,int month){
  std::string str;
  filename>>str;
  Station::years newq;
  for(auto i=0;i<station.vec_years.size();i++){
    if(year==station.vec_years.at(i).year_){
  std::cout<<"Max temp"<<std::string(10,' ')<<"Min temp "<<std::endl;
  std::cout<<station.vec_years.at(i).vec_month.at(month-1).tmax<<std::string(18-station.vec_years.at(i).vec_month.at(month-1).tmax.size(),' ')<<station.vec_years.at(i).vec_month.at(month-1).tmin<<std::endl;
return;
    }
    }
  while(!filename.eof()){
  char c;
   std::string dummy;
    int yr;
  while(c!=','){
    filename>>c;
    dummy.push_back(c);
  }
  filename>>yr;
  if(year==yr){
    newq.year_=yr;
    filename>>c;
    int month;
    filename>>month;
    std::string tmax,tmin;
    filename>>c;
    filename>>c;
    while(c!=','){
      tmax.push_back(c);
      filename>>c;
    }
    while(c<'A'){
      if(c!=',')
      tmin.push_back(c);
      filename>>c;
    }
    if(tmin.size())
    newq.vec_month.at(month-1).tmin=tmin;
    if(tmax.size())
    newq.vec_month.at(month-1).tmax=tmax;
  }
  else{
  filename>>dummy;
  filename>>c;
  }
  }
  std::cout<<"Max temp"<<std::string(10,' ')<<"Min temp "<<std::endl;
  std::cout<<newq.vec_month.at(month-1).tmax<<std::string(18-newq.vec_month.at(month-1).tmax.size(),' ')<<newq.vec_month.at(month-1).tmin<<' '<<std::endl;
}


void insertdata(std::list<Station>& base){
  std::string id;
  Station temp;
  std::cout<<"Inesrt StationID: ";
  std::cin.ignore();
  std::getline(std::cin,id);
  std::cin.clear();
  for(auto it=base.begin();it!=base.end();it++){
    temp=*it;
    if(id==temp.StationID){
      std::cout<<"StationID: "<<temp.name<<std::endl;
      std::cout<<"Enter year: ";
      int year;
      std::cin>>year;
        if(year<=0){
          std::cout<<"Invalid number, try again!"<<std::endl;
          return;
        }
      std::cout<<"Enter month: ";
      int month;
      std::cin>>month;
        if(month<=0 || month>12){
          std::cout<<"Invalid number, try again!"<<std::endl;
          return;
        }
      std::cout<<"Enter Max. temp. : ";
      std::string tmax;
      std::cin>>tmax;
      std::cout<<"Enter Min. temp. : ";
      std::string tmin;
      std::cin>>tmin;
      std::string file=temp.name+".csv";
      std::ifstream filename{file};
      insertTemperature(filename, it , year, month, tmax, tmin);
      return;
    }
  }
  std::cout<<"Station with ID "<<id<<" does not exist. Try Again!"<<std::endl;
}


void insertTemperature(std::istream& filename,std::list<Station>::iterator it, int year, int new_month, std::string maxtemp, std::string mintemp){
  std::string str;
  filename>>str;
  Station::years newq;
  while(!filename.eof()){
  char c;
   std::string dummy;
    int yr;
  while(c!=','){
    filename>>c;
    dummy.push_back(c);
  }
  filename>>yr;
  if(year==yr){
    newq.year_=yr;
    filename>>c;
    int month;
    filename>>month;
    std::string tmax,tmin;
    filename>>c;
    filename>>c;
    while(c!=','){
      tmax.push_back(c);
      filename>>c;
    }
    while(c<'A'){
      if(c!=',')
      tmin.push_back(c);
      filename>>c;
    }
    if(tmin.size())
    newq.vec_month.at(month-1).tmin=tmin;
    if(tmax.size())
    newq.vec_month.at(month-1).tmax=tmax;
  }
  else{
  filename>>dummy;
  filename>>c;
  }
  }
  newq.year_=year;
  it->vec_years.push_back(newq);
  it->vec_years.at(it->vec_years.size()-1).vec_month.at(new_month-1).tmax=maxtemp;
  it->vec_years.at(it->vec_years.size()-1).vec_month.at(new_month-1).tmin=mintemp;
}

