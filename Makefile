.PHONY = build
build:
	platformio run

.PHONY = upload
upload:
	platformio run --target upload

.PHONY = monitor
monitor:
	platformio run --target monitor

.PHONY = clean
clean:
	platformio run --target clean

.PHONY = update-cert
update-cert:
	openssl s_client -connect my.haringey.gov.uk:443 -showcerts -servername my.haringey.gov.uk \
		< /dev/null \
		| sed -ne '/-BEGIN CERTIFICATE-/,/-END CERTIFICATE-/p' \
		| awk 'BEGIN{ print "const char* const cert = R\"EOF(" } { print } END{ print ")EOF\";" }' \
		> src/cert.h

