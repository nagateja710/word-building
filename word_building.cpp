#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<cstdlib>
#include<math.h>
using namespace std;


int lmx=15,bmx=15;
 char v[15][15];

 multimap<char,pair<int,int>> letters;//------------------------------charecter present
string word,word2;//------------------------------------word processing
set<string> over;//---------------------------------all used words
string p1,p2,p,bot="bot";//---------------------------------------player
int s1=0,s2=0;//---------------------------------------score
int str1=0,str2=0;//----------------------------------streak
vector<string> life1,life2,life;//------------------------life
bool flag=true,flag1=false;//-----------------------------note1
bool got=false;//--------------------------------------word used or not
int note1=3;//----------------------------------------------note1 about life
queue<pair<int,int>> q;//-------------------------------------highlight latest word
int dir=0;//------------------------------------------------direction
pair<int,int> lo1;//-----------------------------------------user input position
set<pair<int,int>> has1,has2;//------------------------------combination poss or not
string str6,str7,str8,str66,str77,str88;
int level=2;//-----------------------------------------------difficulty
string section;//--------------------------------------------custom type
char topic;//----------------------------------------------type for lv 3,4
pair<int,string> longest;//-------------------------------------------longest word
bool error; //-----------------------------------------------------error
vector<string> notee;


bool fiind(string);
bool fiind2(string word);
void custom();
void print();
void process();
string describe(int i);
void rules();

 void solve(pair<int,int> point,int index){
    // dir=0;
    // index=0;
    bool yes=false;
    if(over.count(word)==1)return;
    // cout<<point.first+1<<" "<<point.second+1<<" "<<index<<endl;Sleep(4000);
    int row=point.first,col=point.second;
         //----------------------------------------------------------------------------------------------------1  
       int k1=0;int k2=0;
        col=col-index;
        int plus1=0,plus2=0,plus=0;

        has1.clear();
         for(int i=0;i<word.size();i++){
            if(col<0 || col+i>lmx-1)break;
               if(v[point.first][col+i]==' ' || v[point.first][col+i]==word[i]){k1++;
                       if(v[point.first][col+i]==word[i])plus1++;
               has1.insert({point.first,col+i});}
            }

            if(k1==word.size() ){
        // col=col-index;
        if((level%2==0 && has1.count(lo1)==1) ||level%2==1 || p==bot){
        for(int i=0;i<word.size();i++){
             v[row][col+i]=word[i];
             plus=plus1-1;

             q.push({row,col+i});dir=1;
             letters.insert({word[i],{row,col+i}});
            over.insert(word);
            yes=true;

        }        
            //  if(p==p1){str1++;s1=s1+((word.size())*10);}
        //              if(p==p2){str2++;s2=s2+((word.size())*10);}
        }
    }
    //----------------------------------------------------------------------------------------------------1
            
if(k1!=word.size()){
         row=point.first,col=point.second;
         row=row-index;
         
         has2.clear();
    for(int i=0;i<word.size();i++){
        if(row<0 || row+i>lmx-1)break;
        if(v[row+i][point.second]==' ' ||v[row+i][point.second]==word[i]){k2++;
        if(v[row+i][point.second]==word[i])plus2++;
        has2.insert({row+i,point.second});}
    }
    // }
    // row=point.first,col=point.second;
        
    if(k2==word.size()){
        // row=row-index;
        if((level%2==0 && has2.count(lo1)==1) ||level%2==1 || p==bot){
        for(int i=0;i<word.size();i++){
             v[row+i][col]=word[i];
             
            plus=plus2-1;

             q.push({row+i,col});dir=2;
             letters.insert({word[i],{row+i,col}});
             over.insert(word);

        }       
        yes=true;
    }
    }
}
   //----------------------------------------------------------------------------------------------------2
    

    if(str1==3){life1.push_back(">> ");str1=0;}
    if(str2==3){life2.push_back(">> ");str2=0;} 
    
    
    if(k1==word.size() || k2==word.size()){ 
        got=true;
    
  } 
  int n=word.size();
  if(yes==true){
    if(longest.first<n)longest={n,word};
     if(p==p1){str1++;s1=s1+((word.size())*10)+plus*5;}
       if(p==p2){str2++;s2=s2+((word.size())*10)+plus*5;}
 }

    }

 
 

void sett(){
    // describe(10);
cout<<"\n\n             >>WORD BUILDING<< \n\nwelcome!...............................\n\n";
cout<<" ____Create WORDS by using letters present in grid____\n\n      ____score will depend on LENGTH of word____\n\n";
cout<<"player name : ";
cin>>p1;

cout<<"\n against bot     pass & play     \n";
cout<<"      (1)             (2)     \n\n";
cout<<"game mode: ";
char plyr;
cin>>plyr;
int ply=plyr-'0';
if(abs(ply)>1){
    cout<<"\nplayer 2 name : ";
cin>>p2;
}
else
p2="bot";

describe(1);
describe(13);
describe(11);
    srand(time(0));
    int random=rand();
    char ltr='a'+random%26;
    string ltrr;
    ltrr.push_back(ltr);
    longest={1,ltrr};
    int rr=2+random%6,cc=2+(random/2)%6;
       memset(v,' ',lmx*bmx);
        v[rr][cc]=ltr;
        //  v[0][3]='b';
        //   v[3][0]='c';
    // present.insert(ltr);
    letters.insert({ltr,{rr,cc}});
    // print();
}

void process(){
     pair<int,int> point;
       int possible=0;
       int locations;
    for(int i=0;i<word.size();i++){
        locations=(letters.count(word[i]));
        if(locations>0){
            auto it=letters.equal_range(word[i]);
            for(auto im=it.first;im!=(it.second);im++){  
                point=im->second;
               possible++;
             solve(point,i);}
            // for(int j=0;j<locations;j++){auto it=letters.find(word[i],im,letters.end());
             
            //  im=it;
            
            // }
           
        }
    }
if(possible==0){char x;error=true;describe(19);print();got=false;cin>>x;
}
}


void print(){
    pair<int,int> frnt;
    int randd=rand();
    int z=randd%7;
     describe(z);
     if((str1==3 ||str2==3) && note1>0){describe(9);note1--;}
    // if(dir==1)q.pop();
   system("cls");
   if(p==p1)life=life1; else life=life2;
   cout<<" x]|y] 1 |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |  11 | 12  | 13  | 14  |  15 |   >>WORD BUILDING<<\n";//  |  6  |  7  |  8  |  9  | 10  |\n";
//    for(int k=0;k<10*6;k++)cout<<"-";cout<<"-\n";
for(int i=0;i<lmx;i++){
   for(int k=0;k<bmx*6;k++)cout<<"-";
    if(i<9)cout<<"----\n "<<i+1<<"]";
        else cout<<"----\n"<<i+1<<"]";
       for(int j=0;j<bmx;j++){
        frnt=q.front();
        if(i==frnt.first && j==frnt.second){q.pop();cout<<"|| "<<v[i][j]<<" |";dir=0;}
        // cout<<"   "<<v[i][j]<<"  ";
        else cout<<"|  "<<v[i][j]<<"  ";
    }
    cout<<"|";
    if(i==2)cout<<"|| "<<p1<<"'s score="<<s1; 
   else if(i==3)cout<<"|| "<<p2<<"'s score="<<s2;
   else if(level>2 && i==13)cout<<"|| TOPIC: "<<section;
    // else cout<<endl;
if(error==false){
    if(i==0){cout<<"||player: "<<p<<" ";for(auto val:life)cout<<val;cout<<endl;}

     else if(i==10)cout<<str6<<endl;
     else if(i==11)cout<<str7<<endl;
     else if(i==12)cout<<str8<<endl; 
     else cout<<endl;
}
else if(error==true){
     if(i==6){if(life.empty()==true){cout<<"|| "<<p<<" lost CHANCE ";describe(3);}
     else{ 
     cout<<"|| "<<p<<" LOST '>>' [ ";
     for(auto val:life)cout<<val;cout<<"]";
     describe(9);
     }
     }
     if(i==10)cout<<str6<<endl;
     else if(i==11)cout<<str7<<endl;
     else if(i==0)cout<<str66<<endl;
     else cout<<endl;

}


    }
    for(int k=0;k<bmx*6;k++)cout<<"-";cout<<"---->>";

   if(error==false)   {  
if(level%2==0)cout<<"enter location [x y] :";
if(level%2==1)cout<<"enter word :";
}else cout<<"press E to continue  ";

}


int main()
{   
    bool fiiind=false;

// cout<<"**  "<<p1<<"'s turn  **\n";
    sett();
    int chance=1,i=0;
    p=p1;
    string temp1,temp2;
    while(word!="stopp"){ 
        got=false;error=false;
        if(level>4)custom();
        print();
     
             if(s1>=1000 || s2>=1000){describe(14);break;}
        // cout<<"enter location [x y] :";
        if(level%2==0){
if(p!=bot)cin>>temp1>>temp2;
lo1.first=temp1[0]-1-'0';lo1.second=temp2[0]-1-'0';
if(temp1.size()==2)lo1.first=temp1[1]-'0'+9;
if(temp2.size()==2)lo1.second=temp2[1]-'0'+9;
if(level%2==0)cout<<"\n----------------------------------------------------------------------------------------------------enter word---->> : ";
        }
        if(p!=bot)cin>>word;
// cout<<"x"<<endl;Sleep(3000);


        if(word=="stop"){describe(14);word="stopp";continue;}
        if(word=="check"){describe(12);continue;}
        if(word=="rules"){describe(11);continue;}


        if(level>2)fiiind=fiind2(word); else fiiind=fiind(word);

        if(fiiind==true ){char x;
            if(over.count(word)!=0){error=true;
                describe(16);print();
                // cout<<"\n' "<<word<<" ' is completed  <3 \n\npress E to continue  ";
                 if(p==p2){if(life2.empty()!=true)life2.pop_back();else p=p1;chance=1;}
                     else {if(life1.empty()!=true)life1.pop_back();else p=p2;chance=2;}
            ;cin>>x;

            continue;}
     
     process();
   
        }
        if(got==false){ if(p==p2){str2=0;   if(life2.empty()!=true)life2.pop_back();else got=true;} 
                       else {str1=0;        if(life1.empty()!=true)life1.pop_back();else got=true;}}
                       
        if(got==true){if(chance==1){p=p2;chance=2;}
                              else {p=p1;chance=1;}
    }
        }
       
    
    return 0;
}

string describe(int iiii){
// int i;
int fff=0;
char x;
str6.erase();str7.erase();str8.erase();
switch (iiii)
{
    
    case 0:
str6=" HINT : type 'RULES'";
str7="        to see all rules";
str8.erase();
break;
case 1:
if(level<3){
str6="HINT:'SINGLE CHARACTER'";
str7="      can give you 1 point";
str8="      when there is no 'HOPE'";
}else {str6.erase();str7.erase();str8.erase();}
    break;
case 2:
str6=" HINT : type 'CHECK'";
str7="        to check all words used";
str8.erase();
break;

case 3:
str6=" NOTE : every 3 STREAK gives";
str7="        you extra LIFE";
str8.erase();
break;

case 4:
str6=" NOTE : type 'STOP' to ";
str7="        see summary and exit game";
str8.erase();
break;

case 5:
str6=" WARNING : dont underestimate 'BOT' ";
str7="           remember chess bots <D";
str8.erase();
break;

case 9:
str6=" NOTE: '>>' represent LIFE";
str7="       it gives extra chance to play again <3 ";
str8.erase();
break;

// case 10:

// describe(1);
// break;

case 11:
  system("cls");
    cout<<"\n\n             >>WORD BUILDING<< \n\n                 __RULES__ \n\n";
    if(s1!=0)cout<<p1<<"score: "<<s1<<endl;
    if(s2!=0)cout<<p2<<"score: "<<s2<<endl<<endl;
cout<<" ____Create WORDS by using letters present in grid____\n\n";
if(level>2)
cout<<" ____WORDS should only used from TOPIC specified____ \n\n ";
cout<<"      ____score will depend on LENGTH of word____\n\n";
cout<<"\n-] type CHECK to see all words used\n\n-] you lose 'CHANCE' if u not able to frame a word or word is invalid\n\n";
cout<<"-] '>>' represent 'LIFE' gives you extra chance to play";
char temp;
cout<<"\n\npress any key to continue ";
cin>>temp;
break;

case 12:
system("cls");
    // int xxxx=15;
    cout<<"words which have been used :\n\n";

    for(auto val:over){cout<<val;for(int i=0;i<15-val.size();i++)cout<<" ";fff++;if(fff%3==0)cout<<endl;}
cout<<"\n\npress any key to continue ";
cin>>temp;
break;
case 13:
char lv;
system("cls");
    cout<<"\n\n                    >>WORD BUILDING<<\n\n";
    cout<<"welcome : "<<p1<<endl;
    cout<<"        : "<<p2<<endl<<endl;
    cout<<"    novice      rookie      skilled      talented     pro     expert\n";
    cout<<"     (1)         (2)          (3)          (4)        (5)       (6) \n\n";
    cout<<"select dificulty: ";
    cin>>lv;
    level=lv-'0';
    if(level>6)level=1;
if(level==3 || level==4){
    system("cls");
        cout<<"\n\n         >>WORD BUILDING<<\n\n";
        cout<<"difficulty :"<<level<<endl<<endl;
        cout<<"       animals     fruits     vegetables\n";
        cout<<"          (1)        (2)          (3)\n\n\n";
        cout<<"countries     indian states     indian capitals\n";
        cout<<"   (4)             (5)                (6)\n";
        cout<<"\n\nselect topic: ";
        cin>>topic;
        custom();
}
break;
case 14:
  system("cls");
         cout<<"\n\n             >>WORD BUILDING<< \n\n"; 
         cout<<"         __THANK YOU FOR PLAYING__\n\n ";
if(s1>s2)cout<<p1<<" has WON!....CONGRATULATIONS\n\n"; else
         cout<<p2<<" has WON!....CONGRATULATIONS\n\n";
if(s1!=0)cout<<p1<<"'s score: "<<s1<<endl;
if(s2!=0)cout<<p2<<"'s score: "<<s2<<endl<<endl;
        cout<<"LONGEST word used: "<<longest.second<<endl<<endl;

         cout<<"all words used: \n\n";
   for(auto val:over){cout<<val;for(int i=0;i<15-val.size();i++)cout<<" ";fff++;if(fff%3==0)cout<<endl;}
    


cout<<"\n\npress any key to continue ";
cin>>temp;

break;
case 16:
  str66="ERROR: ' "+word+" ' is completed";
//   str6.erase();str7.erase();str8.erase();
//   str77="  <3 \n\npress E to continue  ";

break;
case 17:
  str66="ERROR: ' "+word+" ' is not a valid word";
//   str6.erase();str7.erase();str8.erase();
  break;
case 18:
str66="ERROR: ' "+word+" ' is not a "+section;
// str6.erase();str7.erase();str8.erase();
break;
case 19:
str66="ERROR: ' "+word+" ' cannot be formed with PRESENT CONFIGURATION";

break;
default:
str6.erase();str7.erase();str8.erase();
    break;
}
return str6;
}

int adres(int x){
    switch (x)
    {
    case 0: x=0;            break;
        case 1: x=10000;    break;
        case 2: x=20000;    break;
        case 3: x=30000;    break;
         case 4: x=40000;   break;
        case 5: x=50000;    break;
        case 6: x=60000;    break;
    default:
        break;
    }
    return x;
}
bool fiind( string w){
    int rrr;
    if(p==bot){
        word="dddddd";
                srand(time(0));
    int random=rand();
    int ofset=rand();
    random=random%6;
    ofset=ofset%10000;
    rrr=adres(random)+ofset;
    }
    bool gott=false;
    char x;
    for(int i=0;i<w.size();i++)w[i]=w[i]+3;//---------------------------encode factor 3
string s;
ifstream of("engmix.txt");
bool found=false;int i=0;
while(of.eof()==0){i++;getline(of,s);
if(s==w){found=true;break;}
if(p==bot && rrr==i){
    if(over.count(s)==1){rrr++;continue;}
    word=s;found=true;
      for(int i=0;i<word.size();i++)word[i]=word[i]-3;//---------------------------encode factor 3
    break;}
}

if(found==true)gott=true;
else {error=true;describe(17);print();cin>>x;}
if(word=="dddddd")gott=false;
return gott;
    // }
    // return gott;
}


bool fiind2(string w){
    //   int rrr;
    // if(p==bot){
    //     word="dddddd";
                srand(time(0));
    int random=rand();
    // // int ofset=rand();
    // rrr=5+random%28;
    // }
    bool goti=false;
 bool sec=false; char x;
  for(int i=0;i<w.size();i++)w[i]=w[i]+3;//---------------------------encode factor 3
 string ss,sect;
   ifstream of("custom.txt");
// cin>>section;
sect=section+'{';
 for(int i=0;i<sect.size();i++)sect[i]=sect[i]+3;//---------------------------encode factor 3
 int i=random%5;
while(of.eof()==0){i++;
    getline(of,ss);



    if(sec==true){
        if(ss=="}")break;
       if(ss==w){ goti=true; break;}
    if(p==bot){
    word=ss;
      for(int i=0;i<word.size();i++)word[i]=word[i]-3;//---------------------------encode factor 3
      if(over.count(word)==0){goti=true;break;}
       }
    }
        if(ss==sect)sec=true;
    }
   

if(word=="dddddd"){goti=fiind2(word);}
if(goti!=true){error=true;describe(18);print();cin>>x;}

    return goti;
}

void custom(){
        srand(time(0));
    int random=rand();
    random=random%6;
    char x;
    if(level==3 || level==4){
              random=topic-'0'-1;
    }
    switch(random){
                case 0:
        section="animal";
        break;
                case 1:
        section="fruit";
        break;
                case 2:
        section="vegetable";
        break;
                case 3:
        section="country";
        break;
                case 4:
        section="state";
        break;
                 case 5:
        section="capital";
        break;
    }
}
