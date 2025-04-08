const express = require('express');
const router = express.Router();

// Ejemplo de ruta
router.get('/', (req, res) => {
    const users = [
        { id: 1, name: 'Jesus Vargas', email: 'jesus.vargas@example.com' },
        { id: 2, name: 'Jane Smith', email: 'jane.smith@example.com' },
        { id: 3, name: 'Alice Johnson', email: 'alice.johnson@example.com' }
    ];
    res.json(users);

});

module.exports = router;