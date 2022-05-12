import dotenv from "dotenv";
dotenv.config();
import express from "express";
import login from "./routes/login/login";
import refresh from "./routes/refresh/refresh";
import logout from "./routes/logout/logout";

const app = express();
app.use(express.json());
app.use("/login", login);
app.use("/refresh", refresh);

// OPTIONAL ROUTE
app.use("/logout", logout);

// Main routes

app.listen(4000);
console.log("Listening to port 4000");
