import jwt from "jsonwebtoken";

export const newRefreshToken = (user: jwt.JwtPayload): string => {
  if (!process.env.REFRESH_KEY) {
    return "";
  }

  return jwt.sign(user, process.env.REFRESH_KEY);
};

export const newAccessToken = (user: jwt.JwtPayload): string => {
  if (!process.env.SECRET_KEY) {
    return "";
  }

  return jwt.sign(user, process.env.SECRET_KEY, { expiresIn: "300s" });
};
