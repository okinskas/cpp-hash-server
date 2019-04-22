# cpp-hash-server

## Hash server and client built in C++.

The server accepts [null-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) via socket connections and supports up to 20 concurrent connections by default. The server hashes the string using the SHA256 hash function with 10000 rounds of hashing by default. The response from the server is the resulting hash.

The client provides a simple terminal-based user interface. The client accepts input from the user that it will forward to the server and print out the resulting hash. All input is automatically sent to the server as a null-terminated string so the user does not need to account for that aspect.

The client can be exited by inputting `\q`.

# Deployment

## Server

### Prerequisites

- docker
- docker-compose

To start the server in a docker container, run the following command:

```bash
docker-compose up -d
```

## Client

The client can be built and run via the `run-client` script. Run the following commands:

```bash
chmod +x run-client.sh
./run-client.sh
```

# Other

## Server Logs

Server logs can be accessed via the following command:

```bash
docker-compose logs server
```
