import 'dotenv/config';
import express, { json } from 'express';
import connectDB from './config/database';
import setupSwagger from "./config/swaggerConfig";
import userRoutes from './routes/user.routes';
import productRoutes from './routes/product.routes';
import orderRoutes from './routes/order.routes';


const app = express();




connectDB();

// To expect Content-Type: application/json and process
// https://www.geeksforgeeks.org/express-js-express-json-function/

app.use(json());
setupSwagger(app);


// Rutas
app.use('/api/users', userRoutes);
app.use('/api/products', productRoutes);
app.use('/api/orders', orderRoutes);


// starting server
const PORT = process.env.PORT || 4000;
app.listen(PORT, () => {
    console.log(` Running server on http://localhost:${PORT}`);
});