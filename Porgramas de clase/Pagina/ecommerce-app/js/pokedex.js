// Suponemos que pokemons[] ya está definido en otro archivo o en el mismo HTML
const pokemonsPerPage = 10;
let currentPage = 1;

function renderPokemonCard(pokemon) {
  return `
    <div class="card m-2 p-2" style="width: 12rem;">
      <div class="card-body">
        <h5 class="card-title">#${pokemon.number} - ${pokemon.name}</h5>
        <p class="card-text">Tipo: ${pokemon.type}</p>
      </div>
    </div>
  `;
}

function renderPokedexPage(page, pokemons) {
  const start = (page - 1) * pokemonsPerPage;
  const end = start + pokemonsPerPage;
  const pagePokemons = pokemons.slice(start, end);

  const container = document.getElementById("pokedex-container");
  container.innerHTML = "<div class='d-flex flex-wrap justify-content-center'>" +
    pagePokemons.map(renderPokemonCard).join("") +
    "</div>";
}

function renderPagination(pokemons) {
  const totalPages = Math.ceil(pokemons.length / pokemonsPerPage);
  const pagination = document.getElementById("pagination");
  pagination.innerHTML = "";

  for (let i = 1; i <= totalPages; i++) {
    const li = document.createElement("li");
    li.className = "page-item" + (i === currentPage ? " active" : "");

    const a = document.createElement("a");
    a.className = "page-link";
    a.textContent = i;
    a.href = "#";
    a.addEventListener("click", () => {
      currentPage = i;
      renderPokedexPage(currentPage, pokemons);
      renderPagination(pokemons);
    });

    li.appendChild(a);
    pagination.appendChild(li);
  }
}

function renderPokedex(pokemons) {
  renderPokedexPage(currentPage, pokemons);
  renderPagination(pokemons);
}