import express from "express";
import jwt from "jsonwebtoken";

export default (
  req: express.Request,
  res: express.Response
): express.Response | void => {
  const refreshKey = req.body.token as string;
  if (!refreshKey || refreshKey == "") {
    res.sendStatus(400);
    return;
  }
  if (!process.env.REFRESH_KEY || !process.env.SECRET_TOKEN) {
    res.sendStatus(500);
    return;
  }
  jwt.verify(refreshKey, process.env.REFRESH_KEY, (err, user): void => {
    if (err || !user) {
      res.sendStatus(403);
      return;
    }
    const accessToken = jwt.sign(user, process.env.SECRET_TOKEN as string);
    res.json({ accessToken: accessToken });
  });
};
