const express = require('express');
const router = express.Router();
const userCtrl = require('../controllers/userController');
const auth = require('../middleware/auth');

// Rutas de autenticación
router.post('/', userCtrl.register);
router.post('/login', userCtrl.login);

// Aquí puedes agregar rutas protegidas si quieres probar
// router.get('/privado', auth.verifyToken, (req, res) => res.send('Autenticado'));

module.exports = router;
