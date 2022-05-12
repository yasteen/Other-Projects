import express from "express";
import { newAccessToken, newRefreshToken } from "../../helpers/tokens";

export default (
  req: express.Request,
  res: express.Response
): express.Response | void => {
  if (!req.body.id) {
    return res.sendStatus(500);
  }
  const user = { id: req.body.id as string };

  const accessToken = newAccessToken(user);
  const refreshToken = newRefreshToken(user);
  if (!accessToken || !refreshToken) {
    return res.sendStatus(401);
  }
  // TODO: Save refresh token to DB

  res.json({ accessToken: accessToken, refreshToken: refreshToken });
};
