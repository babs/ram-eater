# ram-eater

Tool to allocate gb of ram to OOM and other resource limits.

```bash
ram-eater AMOUNT_OF_RAM_IN_GB [DELAY]
```

DELAY is the amount of seconds to wait once allocation is done. If omitted or equals 0, wait until killed.


A docker image is available at `beardedbabs/ram-eater:latest`

## License

This software is dual licensed: either [WTFPL](./LICENSE) or [GLWTSPL](./LICENSE.alt)[[source](https://github.com/me-shaon/GLWTPL)] whichever suits you.
