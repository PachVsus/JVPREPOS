function generarNumero() {
    return Math.floor((Math.random() * 12) + 1); // Número aleatorio entre 1 y 12
}

function mostrarNumero() {
    let numero = generarNumero();
    const display = document.getElementById("display");
    display.innerHTML = `<h1> ${numero} </h1>`;
}

function mostrarDados(callback) {
    const display = document.getElementById("display");
    display.innerHTML = `<img src="https://cdn.pixabay.com/animation/2023/11/08/17/50/17-50-28-149_512.gif" alt="dados"></img>`;
    
    // Espera 2 segundos antes de ejecutar el callback (mostrarNumero)
    setTimeout(callback, 2000);
}

// Evento con función flecha para encadenar las funciones
document.getElementById("girar").addEventListener("click", () => mostrarDados(mostrarNumero));

console.log("Saludos desde javascript");
