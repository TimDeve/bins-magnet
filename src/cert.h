const char* const cert = R"EOF(
-----BEGIN CERTIFICATE-----
MIIGWDCCBUCgAwIBAgIQDDX3BPg2XQ/Hd025Fe7XzTANBgkqhkiG9w0BAQsFADBe
MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
d3cuZGlnaWNlcnQuY29tMR0wGwYDVQQDExRUaGF3dGUgVExTIFJTQSBDQSBHMTAe
Fw0yMzA4MjEwMDAwMDBaFw0yNDA5MjAyMzU5NTlaMGAxCzAJBgNVBAYTAkdCMQ8w
DQYDVQQHEwZMb25kb24xIzAhBgNVBAoTGkxvbmRvbiBCb3JvdWdoIG9mIEhhcmlu
Z2V5MRswGQYDVQQDExJteS5oYXJpbmdleS5nb3YudWswggEiMA0GCSqGSIb3DQEB
AQUAA4IBDwAwggEKAoIBAQC6El+UnQr72cGKqM13DBUsvGaS7IMrCf6zY13LRvQa
GmdNqQixJ1XGgEC+CfyeiKf52O9ZaLTMdbA6mpyqyBxGwPV2UosBJtaw4TfJ6WNM
eb5RJ3ez8N7yQdarhDjWAC8YquwWOCH5V19JyA+v00tw2sRqnBXGVBiSHh+SteaR
CEGjZHaPhUSol8tCr0NaVxkI6fUwpbrEmQvTmAxz57wZc27Ac6eE9Fx40LX6fu4Z
A6ZGJo7IfJlXAjJqJy8IjRh6+sYaf7hIrNz/3N1s9sRJiwUl2brsw8nMqTVpd4k6
/nesc8V8XHKGH0mJt0+MgvkD31GQMs4uqzJU17//T4NLAgMBAAGjggMOMIIDCjAf
BgNVHSMEGDAWgBSljP4yzOsPLNQZxgi4ACSIXcPFtzAdBgNVHQ4EFgQU2xF+IEtN
9t7O/eYM07Q/hSz7WeowHQYDVR0RBBYwFIISbXkuaGFyaW5nZXkuZ292LnVrMA4G
A1UdDwEB/wQEAwIFoDAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwOwYD
VR0fBDQwMjAwoC6gLIYqaHR0cDovL2NkcC50aGF3dGUuY29tL1RoYXd0ZVRMU1JT
QUNBRzEuY3JsMD4GA1UdIAQ3MDUwMwYGZ4EMAQICMCkwJwYIKwYBBQUHAgEWG2h0
dHA6Ly93d3cuZGlnaWNlcnQuY29tL0NQUzBwBggrBgEFBQcBAQRkMGIwJAYIKwYB
BQUHMAGGGGh0dHA6Ly9zdGF0dXMudGhhd3RlLmNvbTA6BggrBgEFBQcwAoYuaHR0
cDovL2NhY2VydHMudGhhd3RlLmNvbS9UaGF3dGVUTFNSU0FDQUcxLmNydDAJBgNV
HRMEAjAAMIIBfgYKKwYBBAHWeQIEAgSCAW4EggFqAWgAdwDuzdBk1dsazsVct520
zROiModGfLzs3sNRSFlGcR+1mwAAAYoXJZP3AAAEAwBIMEYCIQDJqXc6j+bAvfuQ
DBUOgC/q+UrvUOzISkfY4vCGQRXy2AIhAIYTqPcdP63bJ3Ohg4tpCMCQl8GrA6aA
5j7gY92Uk0BBAHUASLDja9qmRzQP5WoC+p0w6xxSActW3SyB2bu/qznYhHMAAAGK
FyWUCwAABAMARjBEAiAsvOsI3FLpVw9IXNHBcQ84XkOI4zQV6Ogt1x37BmTYeQIg
clLwknecoKh7oOqhqpsS6YvtizsJsyIOF15gI5Al4isAdgDatr9rP7W2Ip+bwrtc
a+hwkXFsu1GEhTS9pD0wSNf7qwAAAYoXJZPaAAAEAwBHMEUCIB8n+tb4+km2Ba6W
V7tU/q51Op08L2RiQrlT5GaqqJqxAiEAoAnKpO0Yqm/w0nbMV6Rjkvi1Mygqm6Fw
UkCTIu+IENgwDQYJKoZIhvcNAQELBQADggEBAGfOhSNJJwm4BHMbHEyL3eChoFeo
GhUra5hKQYWsh3d+1wMPi0yip0r1sljmTSs3osjtPBboOtUOTWViu3pBy9d/LErv
nCsL+vdUnXO56uLdolPdMdamGWWrNvWXAvxeaLSqAXp/LC2ok1p4LK73Ir6RCYp8
Sq0cBlUSKTxYZyG4NRbx6KO6qdiVPviQDdqwrdjXECwBj9UzAFkh67a6zRLNX7kz
zNrtIWPE/WBGCsclFn5Q1E28V/x/Jkot8oamWxkvR1q16ufvfPU3z7zudkbBYv3W
lSn8oEdthZLzFOzLkyt2D3kTQDSHc27SskrJnNtnlyyrgs1FVPnc8gGVuaA=
-----END CERTIFICATE-----
-----BEGIN CERTIFICATE-----
MIIEizCCA3OgAwIBAgIQCQ7oxd5b+mLSri/3CXxIVzANBgkqhkiG9w0BAQsFADBh
MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBH
MjAeFw0xNzExMDIxMjI0MjVaFw0yNzExMDIxMjI0MjVaMF4xCzAJBgNVBAYTAlVT
MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j
b20xHTAbBgNVBAMTFFRoYXd0ZSBUTFMgUlNBIENBIEcxMIIBIjANBgkqhkiG9w0B
AQEFAAOCAQ8AMIIBCgKCAQEAxjngmPhVetC0b/ozbYJdzOBUA1sMog47030cAP+P
23ANUN8grXECL8NhDEF4F1R9tL0wY0mczHaR0a7lYanlxtwWo1s2uGnnyDs6mOCs
66ew2w3YETr6Tb14xgjpu1gGFtAeewaikO9Fud8hxGJTSwn8xeNkfKVWpD2L4vFN
36FNgxeilK6aE4ykgGAzNlokTp6hNOLAYpDySdLAPKzuJSQ7JCEZ6O+SDKywIdXL
oMTnpxuBKGSG88NWTo3CHCOGmQECia2yqdPDjgLqnEiYNjwQL8uMqj8rOvlMgviB
cHA7xty+7/uYLN6ZS7Vq1/F/lVhVOf5ej6jZdmB85szFbQIDAQABo4IBQDCCATww
HQYDVR0OBBYEFKWM/jLM6w8s1BnGCLgAJIhdw8W3MB8GA1UdIwQYMBaAFE4iVCAY
lebjbuYP+vq5Eu0GF485MA4GA1UdDwEB/wQEAwIBhjAdBgNVHSUEFjAUBggrBgEF
BQcDAQYIKwYBBQUHAwIwEgYDVR0TAQH/BAgwBgEB/wIBADA0BggrBgEFBQcBAQQo
MCYwJAYIKwYBBQUHMAGGGGh0dHA6Ly9vY3NwLmRpZ2ljZXJ0LmNvbTBCBgNVHR8E
OzA5MDegNaAzhjFodHRwOi8vY3JsMy5kaWdpY2VydC5jb20vRGlnaUNlcnRHbG9i
YWxSb290RzIuY3JsMD0GA1UdIAQ2MDQwMgYEVR0gADAqMCgGCCsGAQUFBwIBFhxo
dHRwczovL3d3dy5kaWdpY2VydC5jb20vQ1BTMA0GCSqGSIb3DQEBCwUAA4IBAQC6
km0KA4sTb2VYpEBm/uL2HL/pZX9B7L/hbJ4NcoBe7V56oCnt7aeIo8sMjCRWTCWZ
D1dY0+2KZOC1dKj8d1VXXAtnjytDDuPPf6/iow0mYQTO/GAg/MLyL6CDm3FzDB8V
tsH/aeMgP6pgD1XQqz+haDnfnJTKBuxhcpnx3Adbleue/QnPf1hHYa8L+Rv8Pi5U
h4V9FwHOfphdMXOxi14OqmsiTbc5cOs9/uukH+YVsuFdWTna6IVw1qh+tEtyH16R
vmi7pkqyZYULOPMIE7avrljVVBZuikwARtY8tCVV6Pp9l3VeagBqb2ffgqNJt3C0
TYNYQI+BXG1R1cABlold
-----END CERTIFICATE-----
)EOF";
