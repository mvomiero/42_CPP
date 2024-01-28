MODULE = 04
EX = 00

mvn:
	mvn exec:java -Dexec.mainClass="Module_$(MODULE).ex$(EX).java.Main"

java:
	java -cp target/classes Module_$(MODULE).ex$(EX).java.Main

clean:
	mvn clean install