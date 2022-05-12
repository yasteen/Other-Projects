import express from "express";
import logout from "./logout";

const router = express.Router();
router.post("/", logout);
