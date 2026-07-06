# Tests

## Host unit tests

```bash
bash tools/ci/run_unit_tests.sh
```

Windows PowerShell:

```powershell
powershell -ExecutionPolicy Bypass -File tools/ci/run_unit_tests.ps1
```

Registered CMake tests (with `-DBUILD_HOST_TEST=ON`):

- `test_startup_protection`
- `test_hardware_probe`
- `test_ota_state`

## Release gate

```bash
bash tools/ci/release_gate.sh
```

Windows PowerShell:

```powershell
powershell -ExecutionPolicy Bypass -File tools/ci/release_gate.ps1
```
