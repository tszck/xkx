//  Room:  /d/luoyang/center.c

inherit  ROOM;

void  create  ()
{
	set("short",  "鼓樓");
	set("long",  @LONG
一座跨街大青磚砌的拱洞高臺譙樓，矗立在城中心。鼓樓為二層木
瓦建築，設有大鼓大鐘，晨鐘暮鼓，用以報時。鑄鐵大鐘高五尺，徑亦
近半丈，上鑄八卦和龍鳳梅菊等圖案。 
    鼓樓下來來往往的都是做生意的過客和遊客，無論是來此購買唐三
彩還是欣賞洛陽牡丹的，都不會忘記去城郊的白馬寺和龍門石窟看看。
    路旁邊不顯眼的地方立着一塊石碑(bei)，看起來有些年代了。
LONG);
	set("item_desc",  ([
		"bei" : "
    洛陽：西周時建城，秦置洛陽縣。東周、東漢、三國
魏、西晉、北魏、隋(煬帝)、唐(武后)、後梁、後唐等九
朝故都，是為文化名城，七大古都之一。
\n",
	]));
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastroad",
		"west"  :  __DIR__"westroad",
		"south" :  __DIR__"southroad",
		"north" :  __DIR__"northroad",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
