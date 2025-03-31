const products = [];

function getProducts() {
  return products;
}

function getProductById(uuid) {
  return products.find(p => p.uuid === uuid);
}

function createProduct(product) {
  products.push(product);
}

function updateProduct(uuid, updatedProduct) {
  const index = products.findIndex(p => p.uuid === uuid);
  if (index >= 0) products[index] = updatedProduct;
}

function deleteProduct(uuid) {
  const index = products.findIndex(p => p.uuid === uuid);
  if (index >= 0) products.splice(index, 1);
}

function findProduct(query) {
  let [category, title] = query.split(":").map(x => x.trim());
  return products.filter(p => {
    return (category && p.category.includes(category)) ||
           (title && p.title.includes(title));
  });
}
