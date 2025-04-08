const express = require('express');
const router = express.Router();

// Ejemplo de ruta
router.get('/', (req, res) => {
    res.send('Lista de órdenes');
});

module.exports = router;