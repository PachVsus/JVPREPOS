// Clase Cart para manejar el carrito de compras
class Cart {
    constructor() {
      this.items = []; // Cada item tiene { uuid, amount }
    }
  
    // Agrega producto al carrito (o actualiza la cantidad si ya existe)
    addItem(productUuid, amount) {
      if (amount <= 0) throw new Error("Cantidad debe ser mayor que 0");
      const item = this.items.find(i => i.uuid === productUuid);
      if (item) {
        item.amount += amount;
      } else {
        this.items.push({ uuid: productUuid, amount });
      }
    }
  
    // Actualiza la cantidad de un producto
    updateItem(productUuid, newAmount) {
      if (newAmount < 0) throw new Error("Cantidad negativa no permitida");
      if (newAmount === 0) {
        this.removeItem(productUuid);
      } else {
        const item = this.items.find(i => i.uuid === productUuid);
        if (item) {
          item.amount = newAmount;
        } else {
          throw new Error("Producto no encontrado en el carrito");
        }
      }
    }
  
    // Elimina un producto del carrito
    removeItem(productUuid) {
      this.items = this.items.filter(i => i.uuid !== productUuid);
    }
  
    // Calcula el total de la compra usando la lista de productos completa
    calculateTotal(productsList) {
      return this.items.reduce((acc, item) => {
        const product = productsList.find(p => p.uuid === item.uuid);
        if (!product) return acc;
        return acc + product.price * item.amount;
      }, 0);
    }
  
    // Devuelve todos los productos en el carrito
    getItems() {
      return this.items;
    }
  }