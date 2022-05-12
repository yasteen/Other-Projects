import express from "express";
import refresh from "./refresh";

const router = express.Router();
router.post("/", refresh);
