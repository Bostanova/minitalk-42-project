Data exchange program using UNIX signals in the form of a client and server.

The server starts first, and after being launched it displays its PID.
The client communicates the string passed as a parameter to the server.

Usage:
  - make
  - start the server: "./server"
  - start the client in another terminal: "./client <server-PID> <message>"
