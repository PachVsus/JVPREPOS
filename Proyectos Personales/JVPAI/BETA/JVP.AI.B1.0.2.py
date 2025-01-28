# creacion de asistente virtual AI llamado JVP.AI
# con la posibilidad de seleccionar su genero y actitud desde la configuración inicial
# con opciones de actitud y personalidad como: amable, neutral, de gymbro, de motociclista, de luchador, de militar, de robot, de niño, de niña, de anciano, de anciana, de alien, de fantasma, de vampiro, de zombie, de bruja, de demonio, de angel, de dios, de diablo, de superheroe, de supervillano, de villano, de heroe, de antiheroe, de boxeador, de ninja, de samurai, de pirata, de vaquero, de vaquera, de policia, de ladron, de hacker, de programador, de ingeniero, de cientifico, de doctor, de enfermero, de paciente, de abogado, de juez, de politico, de rey, de reina, de principe, de princesa, de duque, de duquesa, de conde, de condesa, de marques, de marquesa, de baron, de baronesa, de barones, de baronesa, de emperador, de emperatriz, de sacerdote, de monja, de monje, de monarca, de dictador, de tirano, de rehén, de secuestrador, de asesino, de asesina, de asesino en serie, de asesina en serie, de asesino en masa, de asesina en masa, de asesino en serie en masa, de asesina en serie
# Basado en chat de texto
# Mostrando una representuación visual del avatar del asistente virtual.
# con varias funciones de interaccion basica a avanzada
# Autor: Jesus Vargas Pacheco

# Importamos las librerias necesarias
import winreg
import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

# Configuramos las voces del asistente
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

# Menu de configuracion inicial
def configMenu():
    print("Bienvenido a la configuracion inicial de JVP.AI")
    print("Por favor selecciona el genero de tu asistente:")
    print("1. Masculino")
    print("2. Femenino")
    print("3. Salir")

    while True:
        try:
            option = int(input("Selecciona una opcion: "))
            if option == 1:
                print("Has seleccionado genero masculino")
                break
            elif option == 2:
                print("Has seleccionado genero femenino")
                break
            elif option == 3:
                print("Has seleccionado salir")
                break
            else:
                print("Opcion no valida, por favor selecciona una opcion valida")
        except ValueError:
            print("Por favor selecciona una opcion valida")

# Menu de persnalidad y actitud del asistente
def personalityMenu():
    print("Por favor selecciona la personalidad y actitud de tu asistente:")
    print("1. Amable")
    print("2. Neutral")
    print("3. Gymbro")
    print("4. Motociclista")
    print("5. Luchador")
    print("6. Militar")
    print("7. Robot")
    print("8. Niño")
    print("9. Niña")
    print("10. Anciano")
    print("11. Anciana")
    print("12. Alien")
    print("13. Fantasma")
    print("14. Vampiro")
    print("15. Zombie")
    print("16. Bruja")
    print("17. Demonio")
    print("18. Angel")
    print("19. Dios")
    print("20. Diablo")
    print("21. Superheroe")
    print("22. Supervillano")
    print("23. Villano")
    print("24. Heroe")
    print("25. Antiheroe")
    print("26. Boxeador")
    print("27. Ninja")
    print("28. Samurai")
    print("29. Pirata")
    print("30. Vaquero")
    print("31. Vaquera")
    print("32. Policia")
    print("33. Ladron")
    print("34. Hacker")
    print("35. Programador")
    print("36. Ingeniero")
    print("37. Cientifico")
    print("38. Doctor")
    print("39. Enfermero")
    print("40. Paciente")
    print("41. Abogado")
    print("42. Juez")
    print("43. Politico")
    print("44. Rey")
    print("45. Reina")
    print("46. Principe")
    print("47. Princesa")
    print("48. Duque")
    print("49. Duquesa")
    print("50. Conde")
    print("51. Condesa")
    print("52. Marques")
    print("53. Marquesa")
    print("54. Baron")
    print("55. Baronessa")
    print("56. Emperador")
    print("57. Emperatriz")
    print("58. Sacerdote")
    print("59. Monja")
    print("60. Monje")
    print("61. Monarca")
    print("62. Dictador")
    print("63. Tirano")
    print("64. Rehén")
    print("65. Secuestrador")
    print("66. Asesino")
    print("67. Asesina")
    print("68. Asesino en serie")
    
while True:
    configMenu()
    personalityMenu()
    break

# Funcion para dar la bienvenida
def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        print("Buenos dias!")
    elif hour >= 12 and hour < 18:
        print("Buenas tardes!")
    else:
        print("Buenas noches!")
    print("Soy JVP.AI, en que puedo ayudarte?")

# Funcion para reconocer entrada de texto en terminal manual
def takeCommandManual():
    print("Escuchando...")
    query = input("Tu dijiste: ")
    return query

# Funcion principal
if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommandManual().lower()
        if 'wikipedia' in query:
            print('Buscando en Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            print("Segun Wikipedia")
            print(results)
        elif 'abrir youtube' in query:
            webbrowser.open("youtube.com")
        elif 'abrir google' in query:
            webbrowser.open("google.com")
        elif 'abrir stackoverflow' in query:
            webbrowser.open("stackoverflow.com")
        elif 'hora' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            print(f"La hora actual es {strTime}")
        elif 'salir' in query:
            print("Adios!")
            break
        else:
            print("No entiendo, por favor repite...")

# Funcion de autoaprendizaje IA para las respuestas y naturaleza del asistente dependiendo de la personalidad y actitud seleccionada
def learnFromInteraction(personality, attitude, user_input, response):
    # Simulate learning process based on personality and attitude
    # This is a placeholder for a more complex machine learning model
    # For now, it just logs the interaction
    with open("interaction_log.txt", "a") as log_file:
        log_file.write(f"Personality: {personality}, Attitude: {attitude}, User Input: {user_input}, Response: {response}\n")

# Example usage within the main function
if __name__ == "__main__":
    # Assuming personality and attitude are set from the menu
    personality = "amable"  # This should be set based on the user's choice
    attitude = "neutral"    # This should be set based on the user's choice

    wishMe()
    while True:
        query = takeCommandManual().lower()
        response = ""
        if 'wikipedia' in query:
            print('Buscando en Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            response = f"Segun Wikipedia: {results}"
            print(response)
        elif 'abrir youtube' in query:
            webbrowser.open("youtube.com")
            response = "Abriendo YouTube"
        elif 'abrir google' in query:
            webbrowser.open("google.com")
            response = "Abriendo Google"
        elif 'abrir stackoverflow' in query:
            webbrowser.open("stackoverflow.com")
            response = "Abriendo StackOverflow"
        elif 'hora' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            response = f"La hora actual es {strTime}"
            print(response)
        elif 'salir' in query:
            response = "Adios!"
            print(response)
            break
        else:
            response = "No entiendo, por favor repite..."
            print(response)
        
        # Log the interaction for learning
        learnFromInteraction(personality, attitude, query, response)

# Funcion de autoaprendizaje IA para las respuestas y naturaleza del asistente dependiendo de la personalidad y actitud seleccionada para una interaccion mas realista, personalizada y adaptativa.
def learnFromInteraction(personality, attitude, user_input, response):
    # Simulate learning process based on personality and attitude
    # This is a placeholder for a more complex machine learning model
    # For now, it just logs the interaction
    with open("interaction_log.txt", "a") as log_file:
        log_file.write(f"Personality: {personality}, Attitude: {attitude}, User Input: {user_input}, Response: {response}\n")

# Funcion para mejorar la personalidad y actitud del asistente virtual AI basandose de opensource en la web mediante autoaprendizaje IA automatico
def improvePersonality(personality, attitude):
    # Placeholder for actual implementation
    # This function could fetch data from a database or API
    # For now, let's simulate improvement by reading from a predefined set of improvements
    improvements = {
        "amable": "The assistant becomes more polite and considerate.",
        "neutral": "The assistant maintains a balanced and unbiased tone.",
        "gymbro": "The assistant uses more fitness-related language and motivation.",
        # Add more personality improvements as needed
    }
    
    if personality in improvements:
        improvement = improvements[personality]
        with open("personality_improvements.txt", "a") as imp_file:
            imp_file.write(f"Personality: {personality}, Improvement: {improvement}\n")
    else:
        with open("personality_improvements.txt", "a") as imp_file:
            imp_file.write(f"Personality: {personality}, Improvement: No predefined improvement available\n")
    # to improve the personality and attitude of the AI assistant
    pass
