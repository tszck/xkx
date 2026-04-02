// /d/npc/m_weapon/weapon/m_axe.c
// Modified by Zeratul Jan 13 2001 不能鍛鍊在地上的自鑄武器

#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON; 

int do_hui(object weapon);
string QI,JI,upmsg;
string creat_info(object me,string msg1,int flag);
int do_setwmsg(string arg);
string query_autoload() { return 1 + ""; }	//autoload weapon
void copyto(object ob);

void init()
{
	if (!query("inited")) 
	{
		set("inited",1);
	  copyto(this_player());
	}
  if ( !query("desting") && !environment()->is_character() )
  { 
    	set("desting",1);
    	call_out("dest_me",10,this_object());
  };
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
	add_action("do_setwmsg","setwmsg");
}

void copyto(object me)
{
	string w_name,w_id,w_or;
	int w_lv , damage;
	if (!me->query("weapon/make"))
	{
		call_out("destruct",0,this_object());
    return;
  }
  set("inited",1);
//讀入數據
	w_name=me->query("weapon/name");
	w_id = me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	set_name(w_name, ({w_id}));
	set("owner",me->query("id"));
	set("ownmake",1);
	damage = w_lv *10 + me->query("gift/weapon");
	switch (me->query("weapon/type"))
	{
		case "斧":
			set("unit","把");
			set("wield_msg", "$N往腰中一摸，抽出了一把"+w_name+"在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"往身後一別，別在後腰上了。\n");			
			init_axe(damage);
			QI="斧氣";
			JI="指斧背";
			upmsg=CYN"斧身忽的一閃，一道銀光隱入$N的"+w_name+CYN"中，不見了！\n"NOR;
			break;

		case "杖":
			set("unit","杆");
			set("wield_msg", "$N往背後一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一揮，眨眼間已然不見影蹤。\n");			
			init_staff(damage);
			QI="杖體";
			JI="握杖端";
			upmsg=HIY"杖身忽的一亮，一道金光隱入$N的"+w_name+HIY"體，不見了！\n"NOR;
			break;

		case "刀":
			set("unit","柄");
			set("wield_msg", "$N往腰中一抽，拔出了一把"+w_name+"在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"迎風一抖，眨眼間已然不見影蹤。\n");
			init_blade(damage);
			QI="刀氣";
			JI="指刀脊";
			upmsg=CYN"刀身忽的一閃，一道銀光隱入$N的"+w_name+CYN"中，不見了！\n"NOR;
			break;

		case "棍":
			set("unit","根");
			set("wield_msg", "$N往腰中一摸，拿出了一把"+w_name+"，端在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"抖出一個棍花，眨眼間已然不見影蹤。\n");
			init_club(damage);
			QI="兵器";
			JI="指棍脊";
			upmsg=HIY"棍身忽的一亮，似乎一種新生的力量在"+w_name+HIY"中湧動起來！\n"NOR;
			break;

		case "錘":
			set("unit","把");
			set("wield_msg", "$N往後腰中一摸，取出了一柄"+w_name+"握在手中。\n");
			set("unwield_msg","$N手中"+w_name+"往腰後一別，眨眼間已然不見影蹤。\n");
			init_hammer(damage);
			QI="錘氣";
			JI="指錘體";
			upmsg=HIY"錘身忽的一亮，一道金光隱入$N的"+w_name+HIY"體，不見了！\n"NOR;
			break;

		case "鉤":
			set("unit","柄");
			set("wield_msg", "$N「唰」的一聲抽出一把"+w_name+"握在手中。\n");
			set("unwield_msg", "$N將手中的"+w_name+"一抖，白光一閃，轉眼間"+w_name+"已然不見蹤影。\n");
			init_hook(damage + 2);
			QI="兵器";
			JI="捏鉤尖";
			upmsg=HIY"鉤身忽的一亮，一道金光隱入$N的"+w_name+HIY"，不見了！\n"NOR;
			break;

		case "槍":
			set("unit","杆");
			set("wield_msg", "$N往背後一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一揮，眨眼間已然不見影蹤。\n");
			init_spear(damage);
			QI="槍體";
			JI="握槍頭";
			upmsg=HIY"槍身忽的一亮，一道金光隱入$N的+"+w_name+HIY"體，不見了！\n"NOR;
			break;

		case "棒":
			set("unit","根");
			set("wield_msg", "$N往背後一摸，掏出了一杆"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"一揮，眨眼間已然不見影蹤。\n");
			init_stick(damage);
			QI="棒體";
			JI="握棒端";
			upmsg=HIY"棒身忽的一亮，一道金光隱入$N的"+w_name+HIY"體，不見了！\n"NOR;
			break;

		case "劍":
			set("unit","口");
			set("wield_msg", "$N往腰中一帶，抽出了一口"+w_name+"握在手中。\n");
			set("unwield_msg", "$N手中"+w_name+"迎風一抖，眨眼間已然不見影蹤。\n");
			init_sword(damage);
			QI="劍氣";
			JI="指劍脊";
			upmsg=HIY"劍身忽的一亮，一道金光隱入$N的"+w_name+HIY"體，不見了！\n"NOR;
			break;

		case "鞭":
			set("unit","條");
				set("wield_msg", "$N往腰中一摸，刷的抖出了一條"+w_name+"。\n");
				set("unwield_msg","$N手中"+w_name+"一抖，眨眼間捲回腰間不見了影蹤。\n");
			init_whip(damage);
			QI="兵器";
			JI="捏鞭稍";
			upmsg=HIY"鞭身忽的一亮，一道金光隱入$N的"+w_name+HIY"，不見了！\n"NOR;
			break;
			
		default :
			tell_object(me,"你的自鑄武器有錯，請通知巫師解決。\n");
			call_out("destruct",0,this_object());
			return;
	}
	switch(w_or)
	{
		//普通長劍重量 5000
		//兵器初始硬度rigidity 劍== 傷害/4 其它類型有一點比例差別
		case "千年神木" :
			set_weight(2000);
      			add("rigidity",query("rigidity")/3);
			set("material", "wood");
			break;
		case "海底金母" :
			set_weight(30000);
			set("material", "steel");
			break;
		case "寒絲羽竹" :
			set_weight(30);
      			set("material","softsteel");
			break;
		case "隕星鐵石" :
			set_weight(10000);
			add("rigidity",query("rigidity")/2);
			set("material", "iron");
			break;
/*		case "雷火寒晶" :
			set_weight(30000);
			set("material", "golden");  //待開發
*/
		default :
	} 
	set_desc(w_lv,w_or,w_name);
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
  if( me->query("weapon/killed"))
    set("killed", me->query("weapon/killed"));
}

void create()
{	
	set_name("自鑄兵器",({"own weapon"}));
	set("no_get",(: this_player()->query("id") != this_object()->query("owner") :));
	set("no_drop",1);
	set("player",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("unit","柄");
	setup();
}	

int do_duanlian(object weapon)
{
	object me = this_player();
	int w_zhi, w_level;
	string w_name, w_or;

	w_name=me->query("weapon/name");
	w_level = (int)me->query("weapon/lv");

	if (me->query("max_neili") < 100 )
		return notify_fail("你內力修爲不夠，無法鍛鍊兵器。\n");
	if (me->is_busy()) return notify_fail("你現在正忙着呢。\n");

	if ( me->is_fighter()) return notify_fail("戰鬥中無法鍛鍊！\n");

	if( !weapon || !present( weapon, me ) || query("owner")!=me->query("id"))
		return notify_fail("你要鍛鍊什麼？\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("你的內力不夠，無法鍛鍊"+QI+"！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的氣不夠，無法鍛鍊"+QI+"！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你現在的體力太弱，無法鍛鍊"+QI+"！\n");

	if( (int)me->query("jing") < 30 )
			return notify_fail("你現在的精力無法集中，不能鍛鍊"+QI+"！\n");

	if( ((int)me->query("potential") - (int)me->query("learned_points"))< 2 )
		return notify_fail("你的潛能不夠，無法鍛鍊"+QI+"！\n");
		
//	if( w_level >= (int)(me->query("int") + me->query("sta"))/2 )
	if(w_level>=(me->query_con()+me->query_sta())/3
//		||w_level>=60  	//上限600傷害  
		)
	{
		message_vision(RED"$N使勁鍛鍊着"+w_name+RED"，可是好象沒什麼效果！\n"NOR, me);
		return 1;
	}
	message_vision(HIR "$N手"+JI+"，一股內力絲絲的傳了進去。\n" NOR, me);

//	me->start_busy(3);
	me->add("max_neili",-10);
	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("learned_points", 2);

	w_zhi = (int)me->query("weapon/value");
	w_zhi++;
	me->set("weapon/value", w_zhi);
	w_or = (string)me->query("weapon/or");
	
	if( w_zhi >= ((w_level + 1) * (w_level + 1)))
	{
		w_level++;
		me->set("weapon/lv", w_level);
		message_vision(upmsg,me);
		message_vision(HIG"$N的"+w_name+HIG"的等級提高了！\n"NOR, me);
//		weapon=this_object();
//		if(weapon->query("equipped") ) 
//			weapon->unequip();
//		reload_object( weapon );
//		weapon->copyto(me);
		seteuid(getuid());
		weapon=new("/d/npc/m_weapon/weapon/m_weapon");
//		weapon->copyto(me);
		weapon->move(this_player());
		me->set("weapon/value",0);
		destruct(this_object());
		return 1;
	}
	message_vision(RED"$N的"+w_name+RED"的質地改善了！\n"NOR, me);
	return 1;
}

int do_hui(string weapon)
{	
	string w_name;
 object me;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon || !id(weapon)|| query("owner")!=me->query("id"))
		return 0;
//		return notify_fail("你要摧毀什麼？\n");
	message_vision(HIR"$N大喝一聲，一掌擎"+me->query("weapon/type")+"，一掌猛力擊下。結果轟隆一聲巨響"+w_name+HIR"斷爲兩截！\n"NOR,me);
	me->set("weapon/make",0);
//	me->delete("weapon");
	me->save();
	destruct( this_object() );
	return 1;
}

void owner_is_killed()
{
	object piece;
	write(HIY"只見一聲清脆的響聲，"+query("name")+HIY"落在地上，斷成數截。\n"NOR);
	this_object()->unequip();
 	seteuid(getuid());
 	piece = new("/clone/misc/piece");
 	piece->set("long", query("long"));
 	piece->set_name( query("name") + "的碎片", ({query("id"),"piece"}) );
 	if(environment(environment()))
 	  piece->move(environment(environment()));
	destruct(this_object());
}

int do_setwmsg(string info)
{
	int i;
	object me=this_player();
	string msg,command,msg1;
	string *ban_name=({
		"【",		"】",		"仙子",		"風兒",		"巫師",
		"天神",	"告訴",	"回答",
		});
	object weapon;
	if( !info ) return 0;
	if( !(me->query("weapon/make")))
		return notify_fail("你沒有自制的兵器！\n");
	if (strsrch(info, "$N") < 0)
		return notify_fail("描述裏要有$N表示你自己！\n");
	if (strsrch(info, "$WEAPON$") < 0)
		return notify_fail("描述裏要帶$WEAPON$表示你的兵器！\n");
	for (i=0;i<sizeof(ban_name);i++)
	if (strsrch(info, ban_name[i]) > 0)
		return notify_fail("描述裏出現了非法字符！\n");
	weapon = this_object();
	if( !objectp(weapon) || !present(weapon,me)) 
	return notify_fail("你的兵器不在身邊！\n");
	sscanf(info ,"%s %s" ,command ,msg1);
	switch(command)
	{
		case "-w":
			msg = creat_info(me,msg1,1);
			me->set("weapon/wield_msg",msg);
			weapon->set("wield_msg",msg+"\n"NOR);
			break;
		case "-u":
			msg = creat_info(me,msg1,1);
			me->set("weapon/unwield_msg",msg);
			weapon->set("unwield_msg",msg+"\n"NOR);
			break;
		default :
			return notify_fail("描述設置失敗，請選擇具體參數。詳細請
看幫助文件。\n");
	}
	write("Ok.\n");
	return 1;
	}
	
string creat_info(object who,string msg1,int flag)
{
		string w_name,name;
	int w_lv,color;
	w_lv = who->query("weapon/lv");
	w_name = who->query("weapon/name");
	color = (w_lv/10);
	color = w_lv - color*10;
	switch(color){
		case 1:
		case 2:
			name = HIR + w_name + NOR;
			break;
		case 3:
		case 4:
			name = HIG + w_name + NOR;
			break;
		case 5:
		case 6:
			name = HIY + w_name + NOR;
			break;
		case 7:
		case 8:
			name = HIB + w_name + NOR;
			break;
		case 9:
			name = HIM + w_name + NOR;
			break;
		case 0:
			name = HIC + w_name + NOR;
			break;
	}
	if ( flag==2 )
		return name;
	msg1+="$NOR$";
	msg1 = replace_string(msg1, "$WEAPON$",name);
	msg1 = replace_string(msg1, "$BLK$", BLK);
	msg1 = replace_string(msg1, "$RED$", RED);
	msg1 = replace_string(msg1, "$GRN$", GRN);
	msg1 = replace_string(msg1, "$YEL$", YEL);
	msg1 = replace_string(msg1, "$BLU$", BLU);
	msg1 = replace_string(msg1, "$MAG$", MAG);
	msg1 = replace_string(msg1, "$CYN$", CYN);
	msg1 = replace_string(msg1, "$WHT$", WHT);
	msg1 = replace_string(msg1, "$HIR$", HIR);
	msg1 = replace_string(msg1, "$HIG$", HIG);
	msg1 = replace_string(msg1, "$HIY$", HIY);
	msg1 = replace_string(msg1, "$HIB$", HIB);
	msg1 = replace_string(msg1, "$HIM$", HIM);
	msg1 = replace_string(msg1, "$HIC$", HIC);
	msg1 = replace_string(msg1, "$HIW$", HIW);
	msg1 = replace_string(msg1, "$NOR$", NOR);
	if ( flag==1)
		return msg1;
}

void dest_me(object me)
{
	set("desting",0);
	if (!environment(me) || !environment(me)->is_character())
	{
		message_vision("$N慢慢失去靈性，終於化做一堆塵土隨風而逝。\n",me);
    destruct(me);
  }
}