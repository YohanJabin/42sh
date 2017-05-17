#! /bin/env python3

from bottle import *

arr = []
@get('/command')
def home():
    if (os.path.isfile("aff.log") != True):
        subprocess.call('touch aff.log', shell=True)
    with open("aff.log", "r") as file:
        for line in file:
            arr.append(line)
    arr.append("\n")
    return template('home.html', arr=arr)

@post('/command')

def send_command():
    command = request.forms.get('command')
    if command == "clear":
        arr[:] = []
        command = ""
        subprocess.call('rm -f aff.log', shell=True)
    else:
        arr.append("$>" + command)
        full = 'echo "'+command+'" | ../42sh > aff.log'
        print("COMMAND")
        print(full)
        subprocess.call(full, shell=True)
    redirect('/command')

@error(404)
def error404(error):
    return 'THERE ARE NO 42SH HERE :3'

@route('/')
def main():
    if (os.path.isfile("aff.log") != True):
        subprocess.call('rm -f aff.log', shell=True)
    redirect('/command')

run(host='localhost', port=8080, debug=True, reloader=True)
