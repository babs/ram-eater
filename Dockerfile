FROM debian:bookworm AS builder

RUN set -xe \
  && apt update \
  && apt install -y build-essential

COPY . /build/

RUN set -xe \
  && cd /build \
  && make


FROM debian:bookworm-slim

COPY --from=builder /build/ram-eater /usr/local/bin/

ENTRYPOINT [ "/usr/local/bin/ram-eater" ]
