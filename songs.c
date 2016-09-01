#include <stdio.h>

char *titles[]={"Freedbird","YMCA","Sandstorm"};
char *artists[]={"Lynyrd Skynyrd","Village People","Darude"};

struct song_t{
   char *title;
   char *artist;

};
struct playlist_t{
   char* name;
   struct node_t* head;
};
struct node_t{
   struct song_t* song;
   struct node_t* next;
};
void print (struct playlist_t* pl){
   struct node_t* ptr = pl->head;
   while(ptr!=NULL){
      printf("%s by %s\n",ptr->song->title,ptr->song->artist);
      ptr = ptr->next;
   } 
}
int main(int argc, char *argv[]){
   struct song_t song1, song2, song3;
   struct playlist_t pl1, pl2;
   struct node_t p1_s1, p1_s2, p1_s3;
   struct node_t p2_s1, p2_s2, p2_s3;

   song1.title = titles[0];
   song1.artist = artists[0];
   song2.title = titles[1];
   song2.artist = artists[1];
   song3.title = titles[2];
   song3.artist = artists[2];
	
   pl1.name = "Cool Songs for bros";
   p1_s1.song = &song1;
   p1_s2.song = &song2;
   p1_s3.song = &song3;
   p1_s1.next = &p1_s2;
   p1_s2.next = &p1_s3;
   p1_s3.next = NULL;
   pl1.head = &p1_s1;
   print(&pl1);
   return 0;
}
