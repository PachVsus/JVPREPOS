# creacio de asistente virtual AI llamado JVP.AI
# Autor: Jesus Vargas Pacheco

# Importamos las librerias necesarias
from winreg import QueryInfoKey, QueryReflectionKey, QueryValue, QueryValueEx
import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

# Configuramos la voz del asistente
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)

# Funcion para que el asistente hable
def speak(audio):
    engine.say(audio)
    engine.runAndWait()

# Funcion para saludar al asistente
def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour < 12:
        speak("Buenos dias!")
    elif hour >= 12 and hour < 18:
        speak("Buenas tardes!")
    else:
        speak("Buenas noches!")
    speak("Soy JVP.AI, en que puedo ayudarte?")

# Funcion para reconocer la voz
def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Escuchando...")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Reconociendo...")
        query = r.recognize_google(audio, language='es-ES')
        print(f"Tu dijiste: {query}\n")
    except Exception as e:
        print("Repite por favor...")
        return "None"
    return query

#funcion para reconocer entrada de texto en terminal manual
def takeCommandManual():
    print("Escuchando...")
    query = input("Tu dijiste: ")
    return query

# Funcion para enviar correos electronicos
def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('your_email@gmail.com', 'your_password')
    server.sendmail('your_email@gmail.com', to, content)
    server.close()

# Funcion principal
if __name__ == "__main__":
    wishMe()
    while True:
        query = takeCommand().lower()
        if 'wikipedia' in query:
            speak('Buscando en Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("Segun Wikipedia")
            print(results)
            speak(results)
        elif 'abrir youtube' in query:
            webbrowser.open("youtube.com")
        elif 'abrir google' in query:
            webbrowser.open("google.com")
        elif 'abrir stackoverflow' in query:
            webbrowser.open("stackoverflow.com")
        elif 'hora' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"La hora actual es {strTime}")
elif 'enviar correo' in QueryValueEx:
    try:
        speak("Que quieres que diga?")
        content = takeCommand()
        to = "example@example.com"
        sendEmail(to, content)
        speak("Correo enviado!")
    except Exception as e:
        print(e)
        speak("Lo siento, no pude enviar el correo")
elif 'salir' in QueryReflectionKey:
    speak("Hasta luego!")
    

# Fin del programa