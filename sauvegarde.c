#include <stdio.h>
#include <stdlib.h>
#include <fcnt1.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_SIZE 512

int main(int argc, char* argv[]){

	int idFichierLu, idFichierEcrit;
	int byteLu, byteEcrit;
	char buffer[BUF_SIZE];
	char nomFichier[255];

	if(argc == 2){
		idFIchierLu = open (argv [1], O_RDONLY);
		if (idFIchierLu == -1){
			printf ("Erreur de lecture");
			return -1;
		}
	else{
		printf("Nombre de parametre incorrect");
	}

	sprintf(nomFichier, "/home/exia/save/%s", argv[1]);
	idFichierEcrit = open(nomFichier, O_WRONLY | O_CREAT, 0777);
	if(idFichierEcrit == -1){
		printf("Erreur d'ecriture");
		return -2;
	}

	while((byteLu = read(idFichierLu, &buffer, BUF_SIZE)) > 0){
		byteLu = write(idFichierEcrit, &buffer, byteLu);
		if(byteEcrit != byteLu){
			printf ("Erreur d'ecritue dans le fichier");
			return -3;
		}
		else{
			printf("%d byte lue, %dbyte ecrit\n", byteLu, byteEcrit);
		}

	close(idFichierLu);
	close(idFichierEcrit);
