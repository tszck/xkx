//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
  set ("short", "西陵峽");
  set ("long", @LONG
這裏兩岸怪石嶙峋，險崖峭立，猿猴難攀。灘多流急，以“險”出
名，以“奇”著稱，“奇”、“險”化爲壯美。這裏峽中有峽，大峽套
小峽，灘中有灘，大灘含小灘。展現在你眼前的是色彩斑瀾，氣象萬千
的壯麗畫卷。從這裏往西是巫峽，北邊是一片亂石岡。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"wuxia",
		"north": __DIR__"shangang2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
