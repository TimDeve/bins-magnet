.PHONY = build
build:
	platformio run --target debug

.PHONY = upload
upload:
	platformio run --target upload

.PHONY = monitor
monitor:
	platformio run --target monitor

.PHONY = clean
clean:
	platformio run --target clean
