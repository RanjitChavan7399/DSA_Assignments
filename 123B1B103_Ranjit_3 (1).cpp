#include<iostream>
#include<cmath>
using namespace std;

struct song {
  int id;
  string title;
  string artist;
  float duration;
  song* next;
};

class playList {
   private:
   song * head = NULL;
   public:
   void AddSongatpos(){
     song* nn = new song;
     cout<<"Enter :-- Title <space> Artist <space> Duration : ";
     cin>>nn->title>>nn->artist>>nn->duration;
     nn->id = rand() % 10;
     string t;
     cout<<"Enter the title of song which you want to add the song to its next :";
     cin>>t;
     nn->next = NULL;
     if(head == NULL){
        head = nn;
     }
     else {
       song *temp = head;
       while(temp->title == t){
         temp = temp->next;
       }
        if (temp == NULL) {
            cout << "Song with title '" << t << "' not found.\n";
            delete nn;
        } else {
            nn->next = temp->next;
            temp->next = nn;
        }
     }
   }

   void addbeg(){
      song *nn = new song;
      cout<<"Enter :-- Title <space> Artist <space> Duration WHICH YOU WANT TO ADD AT THE BEGEINING: ";
      cin>>nn->title>>nn->artist>>nn->duration;
      if(head == NULL){
        head = nn;
     }
     else{
      song *temp = head;
      nn->next = temp;
      head = nn;
      }
   }
   
   void addatend(){
    song *nn = new song;
    cout<<"Enter :-- Title <space> Artist <space> Duration WHICH YOU WANT TO ADD AT THE END: ";
    cin>>nn->title>>nn->artist>>nn->duration;
    if(head == NULL){
        head = nn;
        return;
    }
    else{
        song *temp = head;
        while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = nn;
    }
   }
   
    void search(){
        song *nn = new song;
        string t;
        cout<<"Enter the title of song which you want :";
        cin>>t;
        if(head == NULL){
            cout<<"List is EMPTY !!!";
            return;
        }
        else{
            song *temp = head;
            while(temp->title == t){
                temp = temp->next;
        }
        cout<<"soong is found :"<<endl;
        cout<<"1. Song Id  : "<<temp->id<<endl;
        cout<<"2. Title    : "<<temp->title<<endl;
        cout<<"3. Artist   : "<<temp->artist<<endl;
        cout<<"4. Duration : "<<temp->duration<<endl;
        }
        cout<<"Sorry! song is not found"<<endl;
    }
   void delatstart(){
    song* temp = head;
    if(head == NULL){
         cout<<"Empty playlist! can't delete"<<endl;
         return;
    }
    else{
        head = head->next;
    }
    cout<<"\nStarting song deleted :"<<endl;
   } 

   void delatend(){
    song *temp = head;
    song *prev = NULL;
    if(head == NULL){
         cout<<"Empty playlist! can't delete"<<endl;
         return;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
         
    }
   }

   void DeleteSong(){
      song* ptr = head;
      string T;
      cout<<"Enter song title for delete : ";
      cin>>T;
      if(head == NULL){
         cout<<"Empty playlist! can't delete"<<endl;
         return;
      }
      if(head->title == T){
         head = head->next;
         return;
      }
      while(ptr->next){
        if(ptr->next->title == T){
          ptr->next = ptr->next->next;
          return;
        }
        else {
          ptr = ptr->next;
        }
      }
     cout<<endl<<T<<" is not found in the playlist!"<<endl;
   }

   void reverse(){
    song *temp = head;
    song *prev = NULL;
    if(head == NULL){
        cout<<"Empty playlist! :"<<endl;
        return;
      }
      while (temp != NULL) {  
        head = temp->next;  
        temp->next = prev;  
        prev = temp;       
        temp = head;        
    }    head = prev; 
    cout << "\nPlaylist reversed successfully! -----given below -----" << endl;
}
   void delall(){
     song* temp = head;
     while (temp != NULL) {
        song* nextSong = temp->next; 
        delete temp;                 
        temp = nextSong;             
     }
     head = NULL;
     cout << "All songs have been deleted.\n";
   }

   void DisplaySong(){
     song* ptr = head;
     if(ptr == NULL){
       cout<<"Your Playlist is Empty"<<endl;
       return;
     }
     while(ptr != NULL){
       cout<<endl;
       cout<<"1. Song Id  : "<<ptr->id<<endl;
       cout<<"2. Title    : "<<ptr->title<<endl;
       cout<<"3. Artist   : "<<ptr->artist<<endl;
       cout<<"4. Duration : "<<ptr->duration<<endl;
       ptr = ptr->next;
     }
   }
};

int main(){
   playList p;
   cout<<endl;
   cout<<"1 for AddSong at given position to playlist"<<endl;
   cout<<"2 for AddSong to start of the playlist"<<endl;
   cout<<"3 for AddSong to end of the playlist"<<endl;
   cout<<"4 for search to playlist"<<endl;
   cout<<"5 for Deleting a song at start of playlist"<<endl;
   cout<<"6 for Deleting a song at end of playlist"<<endl;
   cout<<"7 for Deleting a song at your given titile of playlist"<<endl;
   cout<<"8 for Reverse playlist playlist"<<endl;
   cout<<"9 for deleting all songs from playlist playlist"<<endl;
   cout<<"10 for play playlist"<<endl;
   while(true){
     cout<<endl<<"Enter Choice /> ";
     int choice;
     cin>>choice;
     switch(choice){
       case 1:
        p.AddSongatpos();
        break;      
       case 2:
        p.addbeg();
        break;
       case 3:
        p.addatend();
        break;
        case 4:
        p.search();
        break;
        case 5:
        p.delatstart();
        break;
        case 6:
        p.delatend();
        break;
        case 7:
        p.DeleteSong();
        break;
        case 8:
        p.reverse();
        break;
        case 9:
        p.delall();
        break;
        case 10:
        p.DisplaySong();
        break;
       default:
        system("cls");
        cout<<"\nYou Exit"<<endl<<endl;
        return 0;
     }

   }
   cout<<endl;
   return 0;
}