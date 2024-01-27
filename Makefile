MODULE = 01
EX = 01

mvn:
	mvn exec:java -Dexec.mainClass="Module_$(MODULE).ex$(EX).java.Main"

java:
	java -cp target/classes Module_$(MODULE).ex$(EX).java.Main

clean:
	mvn clean install