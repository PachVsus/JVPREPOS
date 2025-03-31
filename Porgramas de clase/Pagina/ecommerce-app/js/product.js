// Clase Product con validaciones y excepciones
class Product {
    constructor(uuid, title, price, category) {
      if (!title || typeof title !== 'string') {
        throw new Error('Product Exception: Título inválido');
      }
      if (typeof price !== 'number' || price < 0) {
        throw new Error('Product Exception: Precio inválido');
      }
      if (!category || typeof category !== 'string') {
        throw new Error('Product Exception: Categoría inválida');
      }
  
      this.uuid = uuid;
      this.title = title;
      this.price = price;
      this.category = category;
    }
  
    static createFromJson(jsonValue) {
      const obj = JSON.parse(jsonValue);
      return Product.createFromObject(obj);
    }
  
    static createFromObject(obj) {
      const { uuid, title, price, category } = obj;
      return new Product(uuid, title, price, category);
    }
  }
  
  // Array de productos (simula almacenamiento local)
  const products = [];
  
  // CRUD de productos
  function getProducts() {
    return products;
  }
  
  function getProductById(uuid) {
    return products.find(p => p.uuid === uuid);
  }
  
  function createProduct(product) {
    if (!(product instanceof Product)) {
      throw new Error('Debe ser una instancia de Product');
    }
    products.push(product);
  }
  
  function updateProduct(uuid, updatedProduct) {
    if (!(updatedProduct instanceof Product)) {
      throw new Error('Debe ser una instancia de Product');
    }
    const index = products.findIndex(p => p.uuid === uuid);
    if (index !== -1) {
      products[index] = updatedProduct;
    } else {
      throw new Error('Producto no encontrado');
    }
  }
  
  function deleteProduct(uuid) {
    const index = products.findIndex(p => p.uuid === uuid);
    if (index !== -1) {
      products.splice(index, 1);
    } else {
      throw new Error('Producto no encontrado');
    }
  }
  
  function findProduct(query) {
    const [categoryPart, titlePart] = query.split(':').map(s => s.trim());
  
    return products.filter(p => {
      const matchCategory = categoryPart && p.category.toLowerCase().includes(categoryPart.toLowerCase());
      const matchTitle = titlePart && p.title.toLowerCase().includes(titlePart.toLowerCase());
  
      if (categoryPart && titlePart) return matchCategory && matchTitle;
      if (categoryPart && !titlePart) return matchCategory;
      if (!categoryPart && titlePart) return matchTitle;
      return false;
    });
  }