// Room: /d/shaolin/fanting1.c
// Date: YZC 96/01/19

inherit ROOM;

string* names = ({
	__DIR__"obj/mizhi-tianou",
	__DIR__"obj/jiaxin-biji",
	__DIR__"obj/basi-shanyao",
	__DIR__"obj/furong-huagu",
});

void create()
{
	set("short", "齋廳");
	set("long", @LONG
這裏便是少林全寺寺僧用齋的地方。齋廳極大，足可容納上
千人同時進膳。從東到西一排排擺滿了長長的餐桌和長凳，幾位
小和尚正來回忙碌着佈置素齋。桌上擺了幾盆豆腐，花生，青菜
以及素鴨等美味素食。北面是個廚房。
LONG );
	set("exits", ([
		"south" : __DIR__"fanting",
		"north" : __DIR__"chufang",
	]));
	set("objects",([
        	__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 850);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}