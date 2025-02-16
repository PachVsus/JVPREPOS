#!/bin/bash

# Recibir un username y guardarlo en la variable USERNAME
read -p "Ingrese el nombre de usuario: " USERNAME

# Validar si existe el usuario, si no, crearlo y crear su home dir
if id "$USERNAME" &> /dev/null; then
    echo "El usuario $USERNAME ya existe."
else
    sudo useradd -m "$USERNAME"
    if [ $? -eq 0 ]; then
        echo "El usuario $USERNAME ha sido creado."
    else
        echo "Hubo un error al crear el usuario $USERNAME."
    fi
fi

# Crear un directorio en el home del usuario
sudo mkdir /home/"$USERNAME"/scripts
