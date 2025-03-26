#!/bin/bash

# Chemin vers le dossier Main.safe
MAIN_SAFE_DIR="Main.safe"

# Créer le dossier Main.safe s'il n'existe pas déjà
mkdir -p "$MAIN_SAFE_DIR"

# Parcourir tous les dossiers du répertoire courant
for dir in */ ; do
    # Vérifier si le dossier contient un fichier "main"
    if [ -f "$dir/main.c" ]; then
        # Extraire le nom du dossier sans le slash final
        folder_name=$(basename "$dir")

        # Renommer et copier le fichier main dans le dossier Main.safe
        mv "$dir/main.c" "$MAIN_SAFE_DIR/main-$folder_name.c"
        echo "Le fichier 'main' du dossier '$folder_name' a été renommé et copié dans $MAIN_SAFE_DIR"
    else
        echo "Aucun fichier 'main' trouvé dans le dossier '$dir'"
    fi
done
