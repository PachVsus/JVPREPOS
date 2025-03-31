// ======== CREAR PRODUCTOS ========
const p1 = new Product(crypto.randomUUID(), "Laptop HP", 12000, "Tecnología");
const p2 = new Product(crypto.randomUUID(), "Mouse Logitech", 450, "Accesorios");
const p3 = new Product(crypto.randomUUID(), "Monitor Samsung", 3600, "Pantallas");

createProduct(p1);
createProduct(p2);
createProduct(p3);

// ======== MOSTRAR PRODUCTOS EN PANTALLA ========
function renderProductCard(product) {
  return `
    <div class="card m-2 p-2" style="width: 14rem;">
      <div class="card-body">
        <h5 class="card-title">${product.title}</h5>
        <p class="card-text">Categoría: ${product.category}</p>
        <p class="card-text">Precio: $${product.price}</p>
        <button class="btn btn-primary" onclick="addToCart('${product.uuid}')">Agregar al carrito</button>
      </div>
    </div>
  `;
}

function showProducts() {
  const container = document.getElementById("product-container");
  container.innerHTML = "<div class='d-flex flex-wrap'>" +
    getProducts().map(p => renderProductCard(p)).join("") +
    "</div>";
}

// ======== CARRITO DE COMPRAS ========
const cart = new Cart();

function addToCart(uuid) {
  cart.addItem(uuid, 1);
  alert("Producto agregado al carrito");
  updateCartSummary();
}

function updateCartSummary() {
  const summary = document.getElementById("cart-summary");
  const total = cart.calculateTotal(getProducts());
  summary.textContent = `Total del carrito: $${total}`;
}

// ======== EJECUCIÓN INICIAL ========
document.addEventListener("DOMContentLoaded", () => {
  showProducts();
  updateCartSummary();

  // Si quieres probar la Pokédex, descomenta esto:
  // renderPokedex(pokemons);
});

document.addEventListener("DOMContentLoaded", () => {
    showProducts();
    updateCartSummary();
  
    // Mostrar Pokédex
    renderPokedex(pokemons);
  });
  