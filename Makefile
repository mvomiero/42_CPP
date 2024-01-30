MODULE = 05
EX = 00

mvn:
	mvn -X exec:java -Dexec.mainClass="Module_$(MODULE).ex$(EX).java.Main"

java:
	java -cp target/classes Module_$(MODULE).ex$(EX).java.Main

clean:
	mvn clean install