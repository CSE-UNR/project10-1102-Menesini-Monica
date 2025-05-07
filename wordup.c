//Monica Menesini
//Project 10
//May 6th, 2025

#include <stdio.h>
#include <stdbool.h>

#define WORD_LENGTH 5
#define MAX_GUESS 6

void mystery_word(char word[]);
void get_guess(char guess[], int guessNum);
void lowercase(char guess[]);
void copy_of_str(char dest[], char src[]);
void guess_display(char guesses[][WORD_LENGTH + 1], int guess_counter, char mystery[]);
bool is_guess(char guess[]);
bool str_match(char a[], char b[]);
int str_length(char str[]);

int main(){
	char mystery[WORD_LENGTH + 1];
	char guesses[MAX_GUESS][WORD_LENGTH + 1];
	int guess_counter = 0;
	bool won = false;
mystery_word(mystery);

while(guess_counter < MAX_GUESS && !won){
	char guess[WORD_LENGTH + 1];
if(guess_counter == MAX_GUESS - 1){
	printf("FINAL GUESS : ");
}else{
	printf("GUESS %d! Enter your guess: ", guess_counter + 1);
}
	get_guess(guess, guess_counter + 1);
	lowercase(guess);
	copy_of_str(guesses[guess_counter], guess);
	printf("================================\n");
	guess_display(guesses, guess_counter + 1, mystery);
if(str_match(guess, mystery)){
	won = true;
}
	guess_counter++;
}
	printf("================================\n");
if(won){
	printf("You won in %d guess%s!\n", guess_counter, guess_counter == 1 ? "" : "es");
if(guess_counter <= 2){
	printf("Amazing!\n");
}else if(guess_counter <= 4){
	printf("Great job!\n");
}else{
	printf("Nice!\n");
}
}else{
	printf("You lost, better luck next time!\n");
}
return 0;
}
void mystery_word(char word[]){
	FILE *fp = fopen("mystery.txt", "r");
if (fp == NULL){
	printf("Error: could not open mystery.txt\n");
	word[0] = '0';
	return;
}
for(int i = 0; i < WORD_LENGTH; i++){
	word[i] = fgetc(fp);
}
	word[WORD_LENGTH] = '\0';
fclose(fp);
}
void get_guess(char guess[], int guessNum){
while(true){
	scanf("%5s", guess);
while(getchar() != '\n');
if(str_length(guess) != WORD_LENGTH){
	printf("Your guess must be 5 letter long. \nPlease try again: ");
}else if(!is_guess(guess)){
	printf("Invalid guess. Only letters allowed. \nPlease try again: ");
}else{
	break;
}
}
}
void lowercase(char guess[]){
for(int i = 0; i < WORD_LENGTH; i++){
	if(guess[i] >= 'A' && guess[i] <='Z'){
		guess[i] += ('a' - 'A');
}
}
}
bool is_guess(char guess[]){
for(int i = 0; i < WORD_LENGTH; i++){
	char c = guess[i];
if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))){
	return false;
}
}
	return true;
}
int str_length(char str[]){
int count = 0;
while(str[count] != '\0') count++;
	return count;
}
bool str_match(char a[], char b[]){
for(int i = 0; i < WORD_LENGTH; i++){
if(a[i] != b[i])
return false;
}
return true;
}
void copy_of_str(char dest[], char src[]){
for(int i = 0; i < WORD_LENGTH; i++){
	dest[i] = src[i];
}
	dest[WORD_LENGTH] = '\0';
}
void guess_display(char guesses[][WORD_LENGTH +1], int guess_counter, char mystery[]){
for(int g = 0; g < guess_counter; g++){
bool matched_mystery[WORD_LENGTH] = {false};
bool matched_guess[WORD_LENGTH] = {false};
for(int i = 0; i < WORD_LENGTH; i++){
if(guesses[g][i] == mystery[i]){
	matched_mystery[i] = true;
	matched_guess[i] = true;
	char upper = guesses[g][i];
if(upper >= 'a' && upper <= 'z'){ 
	upper -= ('a' - 'A');
}
	printf("%c", upper);
}else{
	printf("%c", guesses[g][i]);
}
}
	printf("\n");
for(int i = 0; i < WORD_LENGTH; i++){
if(matched_guess[i]){
	printf(" ");
	continue;
}
bool found = false;
for(int j = 0; j < WORD_LENGTH; j++){
if(!matched_mystery[j] && guesses[g][i] == mystery[j]){
	matched_mystery[j] = true;
	found = true;
	break;
	}
}
	printf("%c", found ? '^' : ' ');
}
	printf("\n");
}
}




		





