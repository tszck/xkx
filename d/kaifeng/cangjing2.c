// /kaifeng/cangjing2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "藏經樓二層");
	set("long", @LONG
小樓的四個角落中放着石灰包，用來吸收空氣中的水份。每隔段時
間，寺廟中的和尚會把收藏在盒中的佛經放到外面去曬以防日久被蟲子
蛀了，用來晾曬佛經的石頭就稱為曬經石，據説有佛力。
LONG);
	set("objects", ([
		BOOK_DIR"fojing2" : random(6),
	]));
	set("exits", ([
		"down" : __DIR__"cangjing1",
	]));

	setup();
	replace_program(ROOM);
}
