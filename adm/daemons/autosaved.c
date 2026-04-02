// autosaved.c
// file:		Autosave daemon

// 唯一續命八丸和風傳通告 自動存盤由condition做

inherit F_DBASE;

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <command.h>

// #pragma save_binary



void auto_save();
void check_dns();

void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "內存精靈");
	CHANNEL_D->do_channel(this_object(), "sys", "風聞頻道系統已經啓動。\n");
	remove_call_out("auto_save");
	call_out("auto_save", 10);
}

void auto_save()
{
	string *ms = ({
HIM"有人：“想逞英雄麼？揚州忠烈祠的神龕裏的東西，就夠你灌一壺的了。”",
HIM"有人：“自古哪個門派沒有不肖之徒？問問你掌門師尊你能否協助清理門戶，誅殺本門叛徒，追回本門祕籍。”",
HIM"林震南：“我福威鏢局近年來越發興旺了，滿貨倉的貨等待發運，誠請天下有為鏢師，共圖富貴！”",
HIM"衙役：“最近年成不好，兵匪流行，揚州知府大人正在招募捕快，維持治安。雖無薪水，也能露臉！”",
HIR"某人：“江湖中人最恨欺師叛教之輩了。叛徒都無法得到師長真傳，據説各派掌門人都不收叛徒了。”",
HIR"醉仙樓冼老闆：“小店承辦壽宴、婚宴、豪宴，有錢的大老爺二妹子們快快有請哪！”",
HIR"茶博士：“長安樂坊裏，骰子、棋牌、鬥雞、賽龜，真是應有盡有。何不去試試手氣？”",
HIR"紅娘：“小小紅娘我，也算有尺寸功勞。這西湖斷橋邊，聚散都是有緣的人。”",
HIG"胡慶餘：“老夫我，世居杭州，懸壺濟世，欲知端的，來看招牌。”",
HIG"某人：“把人賣到麗春院可也太損了，不過大爺我就喜歡賣人，積點德，賣給唐楠也湊合了。”",
HIC"守園道長：“我武當的人蔘果為萬木之祖，那是我輩練武之人夢寐以求的靈丹。”",
HIC"蕭峯：“據説關外有新鮮熊膽，喫了大長功力。”",
HIC"某人：“如果你還沒想好拜哪個門派，就先到揚州武館或成都金牛武館學點基本功。”",
HIG"歐冶子：“天下工匠，我從不做二人想。想要稱手兵刃，還到回疆沙漠來找我。”",
HIG"某人：“聽説結婚後，在桃花村可以自己蓋房生子，真是大妙！夫人，同去同去。”",
HIB"有人：“朱熹老夫子在揚州授業頒發學位，你我兄弟也去混張文憑如何？”",
HIB"梅超風：“老賊，師父他老人家精通陰陽八卦，掐指一算，立知我們所在。我們還是往北逃得越遠越好。”",
HIY"風清揚：“獨孤九劍為天下劍術之最。要想多勝少敗，苦練二十年，便可和天下英雄一較長短了。”",
HIG"慕容復：“以彼之道，還施彼身！如果想體會天下所有絕招的樂趣，與天下英雄一試高低，便得好好學好鬥轉星移。”",
HIG"王語嫣：“在我家的琅繯玉洞和燕子塢的還施水閣，收藏着普天下門派的祕籍。”",
HIY"張無忌：“乾坤大挪移源自波斯。可化敵攻勢於無形，或借勢反擊，以彼之力，制敵於飄逸之間，是天下一等一的騰挪功夫。”",
HIR"洪七公：“丐幫是天下第一大幫會。探聽江湖信息是本幫的拿手本事，本幫的密道窮極數代幫眾之力，四通八達。”",
HIG"柳含翠：“想給心上人送朵花兒嗎？維揚花店代辦時鮮花卉。”",
HIG"殷天正：“老夫內功修為差強人意，火蟾之功卻也不小。”",
/*HIW"
    古墓幽居癡心人
    倚天屠龍恨太遲
    綠茵浪子來時路
    酒國英雄遽已逝
    驚濤漫卷千重浪
    梵音輕誦百卷詩
    巴蜀狂人放歌處
    泥潭摯友長相思"*/
	});
	string hui_chun, yan_yang;
 int huichun, yanyang, usernum, i;
	object *ob, *inv;
 

message("channel:snow", HIY"【風聞】"+ms[random(sizeof(ms))]+"\n"NOR,users());
	if (file_size("/d/shenlong/cangku.c"))
	  if (!find_object("/d/shenlong/cangku"))
	    load_object("/d/shenlong/cangku");
	if (uptime()<400)
	{
		write_file("/data/XUMING", "1", 1);
		write_file("/data/HUICHUN", "0", 1);
		write_file("/data/YANGYAN", "0", 1);
	}
	hui_chun = read_file("/data/HUICHUN", 1, 1);
	huichun = atoi(hui_chun);
	if(huichun == 0 && uptime() > 86400)
	{
		write_file("/data/HUICHUN", "1", 1);
	}
	yan_yang = read_file("/data/YANGYAN", 1, 1);
	yanyang = atoi(yan_yang);
	if(yanyang == 0 && uptime() > 43200)
	{
		write_file("/data/YANGYAN", "1", 1);
	}
// 清除斷線或發呆20分鐘以上的玩家 鋒鋭兵器定時消失
//	ob = objects();
	ob = children(USER_OB);
	for (usernum=0; usernum<sizeof(ob); usernum++)
	{
		if (!clonep(ob[usernum])) continue;
		if (!environment(ob[usernum])) {destruct(ob[usernum]);continue;}
		if(userp(ob[usernum]) && !wizardp(ob[usernum]))
		{
			if( !interactive(ob[usernum])  ||
				( query_idle(ob[usernum]) > 2400 && !environment(ob[usernum])->is_chat_room()))
			{
				if (!interactive(ob[usernum]) && random(3)>0)
				continue;
				if (time()-ob[usernum]->query_temp("LAST_PKER_TIME")<7200)
					continue;
				"/cmds/usr/exit"->savequit(ob[usernum]);
			}
			else
			{
				inv = all_inventory(ob[usernum]);
				for(i=0; i<sizeof(inv); i++)
				{
				 if ( ob[usernum]->is_fighting())
                			inv[i]->set_temp("keep",0);
        			 else
        			  {
					  if( !inv[i]->is_unique()
					  &&  inv[i]->query("weapon_prop/damage") >= 100
				    &&  !inv[i]->query("ownmake"))
					     inv[i]->add_temp("keep", 1);
					  if( inv[i]->query_temp("keep") > 6 )
				  	{
					  	message("channel:snow",HIM"【謠言】某人："+"遺失多年的"NOR+inv[i]->name()+HIM"又重現江湖啦。\n"NOR, users());
				  		log_file( "WEAPON", sprintf("%20s leave %10s at %s.\n", ob[usernum]->query("name")+ "(" + ob[usernum]->query("id")+")", inv[i]->name(), ctime(time())));
					  	destruct(inv[i]);
					  }
				   }
				}
			}
		}
	}

// 泥巴互聯啓動
	check_dns();
// 判斷浩劫系統是否引發
	if ( LOGIN_D->get_dienpc() > 3000 ) call_out("haojie",0);
	remove_call_out("auto_save");
	call_out("auto_save", 1200+random(20));
}

void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;

	if(!dns = find_object(DNS_MASTER))
	// dns not started, not our problem
	return;
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	if(sizeof(muds)<= 1)
	{
		destruct(dns);
		call_other(DNS_MASTER,"???");
	}
	return;
}
// 浩劫系統的開始
void haojie()
{
	message("channel:snow",HIM"【謠言】江湖。。。一個充滿神祕和危險的世界，太久的平靜似乎預示着暴風雨來\n臨的前夕，人在江湖，身不由己，總是要去面對一次一次的挑戰和危機，誰又能知道明\n天是否依然是如此的安寧呢？\n\n"NOR,users());
	message("channel:snow",HIM"【謠言】江湖上最近出現一個神祕組織，妄想消滅各門派，一統江湖。\n\n\n"NOR,users());
	DISASTER_D->disaster(0);
}