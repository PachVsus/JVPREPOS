const express = require('express');
const router = express.Router();

// Ruta de ejemplo
router.get('/', (req, res) => {
  res.send('Ruta de órdenes funcionando.');
});

module.exports = router;
