# Recibir el nombre de un grupo y guardarlo en la variable GROUPNAME
# Si el grupo no existe, crearlo y crear un directorio en /tmp/ con el nombre del grupo
# Cambiar el ownership del directorio creado al grupo correcto

#!/bin/bash

# Recibir el nombre de un grupo y guardarlo en la variable GROUPNAME
read -p "Ingrese el nombre del grupo: " GROUPNAME

# Validar si existe el grupo, si no, crearlo y crear un directorio en /tmp/ con el nombre del grupo
if grep -q "^$GROUPNAME:" /etc/group; then
    echo "El grupo $GROUPNAME ya existe."
else
    sudo groupadd "$GROUPNAME"
    if [ $? -eq 0 ]; then
        echo "El grupo $GROUPNAME ha sido creado."
        sudo mkdir /tmp/"$GROUPNAME"
    else
        echo "Hubo un error al crear el grupo $GROUPNAME."
    fi
fi

# Cambiar el ownership del directorio creado al grupo correcto
sudo chown :"$GROUPNAME" /tmp/"$GROUPNAME"

# Obtener el nombre de usuario actual y guardarlo en la variable USERNAME
USERNAME=$(whoami)

# Crear un directorio en el home del usuario
sudo mkdir /home/"$USERNAME"/scripts