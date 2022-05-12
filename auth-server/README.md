# auth-server
A simple authentication server using JWT tokens.

- The `login` route returns an access token and a refresh token.
- The `refresh` route takes a refresh token and returns a new access token.
- The `logout` route is optional and would provide a way to instantly invalidate a refresh token.
  The disadvantage to this would be having to store these tokens somewhere (database).
