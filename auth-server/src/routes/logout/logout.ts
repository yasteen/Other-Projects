import express from "express";

export default (
  req: express.Request,
  res: express.Response
): express.Response | void => {
  if (!req.body.token) {
    res.sendStatus(400);
    return;
  }

  // TODO: Delete refresh token from database
};
