# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<stdbool.h>

// Define SongData structure
typedef struct {
    char title[100];
    char artist[100];
    char album[100];
} SongData;

// Define SongNode structure
typedef struct SongNode{
    SongData data;
    struct SongNode* next;
    struct SongNode* previous;
} SongNode;

// Define MusicPlaylist ADT
typedef struct {
    SongNode* playlist_head;
    SongNode* playlist_tail;
    SongNode* now_playing;
} MusicPlaylist;

// Function to create a new MusicPlaylist
MusicPlaylist* create_playlist() {
    MusicPlaylist* playlist = (MusicPlaylist*)malloc(sizeof(MusicPlaylist));
    if (playlist != NULL) {
        playlist->playlist_head = NULL;
        playlist->playlist_tail = NULL;
        playlist->now_playing = NULL;
    }
    return playlist;
}

// Function to create a new SongNode
SongNode* create_song_node(SongData data) {
    SongNode* newNode = (SongNode*)malloc(sizeof(SongNode));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    return newNode;
}

// Function to add a new song to the playlist
void add_song( MusicPlaylist* playlist, SongData data) {
    SongNode* newNode = create_song_node(data);
    if (newNode == NULL) {
        printf("Memory Allocation Failed. Cannot add song.\n");
        return;
    }

    if (playlist->playlist_head = NULL) {
        playlist->playlist_head = newNode;
        playlist->playlist_tail = newNode;
    } else {
        playlist->playlist_tail->next = newNode;
        newNode = playlist->playlist_tail;
        playlist->playlist_tail = newNode;
    }
}

// Function to display all songs in the playlist
void display_playlist(MusicPlaylist* playlist) {
    printf("Playlist:\n");
    SongNode* current = playlist->playlist_head;
    while (current != NULL) {
        printf("%s - %s (%s)\n", current->data.title, current->data.artist, current->data.album);
        current = current->next;
    }
}

int main() {
    // Test the MusicPlaylist ADT
    MusicPlaylist* playlist = create_playlist();

    // Add some sample songs
    SongData song1 = {"Song 1", "Artist 1", "Album 1"};
    SongData song2 = {"Song 2", "Artist 2", "Album 2"};
    SongData song3 = {"Song 3", "Artist 3", "Album 3"};
    add_song(playlist, song1);
    add_song(playlist, song2);
    add_song(playlist, song3);

    // Display the playlist
    display_playlist(playlist);

    return 0;
}