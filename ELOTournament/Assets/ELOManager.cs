using UnityEngine;
using System.Collections.Generic;

public class ELOManager : MonoBehaviour {

    public string Username { get; set; }
    public float ELO { get; set; }
    public float min { get; set; } //minutos de uso

    int Round;

    float AvgUp = 0;  //People above yourself
    float AvgDown = 0;  //People below yourself
    float ProbWinUp = 0;  //Probability to beat people that have beaten you
    float ProbWinDown = 0;  //Probability to beat people you have beaten
    float WinELO = 0; //Score that he will win
    float LoseELO = 0; //Score that he will lose
    float k; //Constant k. It is the maximum score that a user can win/lose in a game
    int userUp = 0; //Users above you in the ranking
    int userDown = 0; //Users below you in the ranking


    public float timer;
    List<ELOManager> Ranking = new List<ELOManager>();
    List<float> winELOList = new List<float>();
    List<float> loseELOList = new List<float>();

    public ELOManager(string Username, float ELO, float min)
    {
        this.Username = Username;
        this.ELO = ELO;
        this.min = min;
    }
    void Init()
    {
        if(Ranking == null)
        {
           Ranking = new List<ELOManager>();
        }
        if(winELOList == null)
        {
            winELOList = new List<float>();
        }
        if (loseELOList == null)
        {
            loseELOList = new List<float>();
        }
    }

	void Start () {
        Init();       

        var user1 = new ELOManager("AAAAAAA", 1000, 1);
        var user2 = new ELOManager("BBBBBBB", 1000, Random.Range(50, 100));
        var user3 = new ELOManager("User3", 1000, Random.Range(50, 100));
        var user4 = new ELOManager("User4", 1000, Random.Range(50, 100));
        var user5 = new ELOManager("User5", 1000, Random.Range(50, 100));
        var user6 = new ELOManager("User6", 1000, Random.Range(50, 100));
        var user7 = new ELOManager("User7", 1000, Random.Range(50, 100));
        var user8 = new ELOManager("User8", 1000, Random.Range(50, 100));
        var user9 = new ELOManager("User9", 1000, Random.Range(50, 100));
        var user10 = new ELOManager("User10", 1000, 9999);

        Ranking.Add(user1);
        Ranking.Add(user2);
        Ranking.Add(user3);
        Ranking.Add(user4);
        Ranking.Add(user5);
        Ranking.Add(user6);
        Ranking.Add(user7);
        Ranking.Add(user8);
        Ranking.Add(user9);
        Ranking.Add(user10);                
    }
	
	void Update () {
        timer += Time.deltaTime;
        if (timer > 3)  //Cada 3 segundos se ejecuta el código
        {
            Round++;
            RandomTimes();
            CalculateELO();
            GiveELO();            
            timer = 0;
        }
	}

    void CalculateELO()   //We calculate the score that each user will win/lose
    {
        Ranking.Sort((p1, p2) => p1.min.CompareTo(p2.min)); //We order the rank by less used to more used
        print("-------------------------------------------------------------------------------- Round: " + Round);

        for (int i = 0; i < Ranking.Count; i++)  //Counts how many users are in the ranking
        {
            AvgUp = 0;  
            AvgDown = 0;  
            ProbWinUp = 0;  
            ProbWinDown = 0;  
            WinELO = 0; 
            LoseELO = 0; 
            k = 5;
            userUp = 0; 
            userDown = 0; 

            userUp = i;  //Number of users above you is the same as "i"
            userDown = Ranking.Count - i;  //Total users - Me

            if (i != 0)  //If you are not the first one
            {
                AvgUp = Ranking[i - 1].ELO;          //AvgUp = Average ELO of people above you
                ProbWinUp = 1 / (1 + Mathf.Pow(10, (AvgUp - Ranking[i].ELO) / 400));
                LoseELO = k * (0 - ProbWinUp) * userUp;
            }
            else if(i == 0) //If you are the first one
            {
                AvgUp = 0;
                LoseELO = 0;
            }
            if (i != Ranking.Count -1 ) //If you are not the last one
            {
                AvgDown = Ranking[i + 1].ELO;       //People below you
                ProbWinDown = 1 / (1 + Mathf.Pow(10, (AvgDown - Ranking[i].ELO) / 400));
                WinELO = k * (1 - ProbWinDown) * userDown;
            }
            else if (i == Ranking.Count)  //If you are the last one
            {
                AvgDown = 0;
                WinELO = 0;
            }
            

            if (Ranking[i].ELO <= 400) //If a user has too low score, we add him some extra points to avoid reaching negative score. That creates ELO inflation
            {
                WinELO += 10;
            }
            else if (Ranking[i].ELO <= 200)
            {
                WinELO += 30;
            }
            else if (Ranking[i].ELO <= 100)
            {
                WinELO += 50;
            }
            winELOList.Add(WinELO);
            loseELOList.Add(LoseELO);
            

            print(Ranking[i].Username + " ELO:" + Ranking[i].ELO + " Min:" + Ranking[i].min + " AvgUp: " + AvgUp + " AvgDown: " + AvgDown + " ProbUp: " + ProbWinUp + " ProbDown: " + ProbWinDown + " WinELO: " + WinELO + " LoseELO: " + LoseELO);            
        }
    }

    void GiveELO()    //We distribute calculated points among the users
    {
        for(int i = 0; i < Ranking.Count; i++)
        {
            Ranking[i].ELO += winELOList[i];
            Ranking[i].ELO += loseELOList[i];
        }
    }
    void RandomTimes()  //We add random time in order to do tests
    {
        for(int i = 0; i<Ranking.Count; i++)
        {
            Ranking[i].min = Random.Range(10, 500);
        }
    }
}
