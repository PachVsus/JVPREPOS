#!/bin/bash

# Function to display the main menu
show_main_menu() {
    dialog --clear --title "Main Menu" \
    --menu "Choose an option:" 15 50 4 \
    1 "Option 1" \
    2 "Option 2" \
    3 "Option 3" \
    4 "Exit" 2>menu_choice.txt

    menu_choice=$(<menu_choice.txt)
    case $menu_choice in
        1) show_option "Option 1";;
        2) show_option "Option 2";;
        3) show_option "Option 3";;
        4) exit 0;;
    esac
}

# Function to display a selected option
show_option() {
    dialog --clear --title "$1" --msgbox "You selected $1" 10 30
    show_main_menu
}

# Ensure dialog is installed
if ! command -v dialog &> /dev/null
then
    echo "dialog could not be found, please install it."
    exit
fi

# Main loop
while true; do
    show_main_menu
done