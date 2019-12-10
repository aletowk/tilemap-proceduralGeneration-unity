using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.Tilemaps;

public class GenerateTileMap : MonoBehaviour
{

    public int mapWidth;
    public int mapHeight;

    public Tilemap baseTilemap;

    public Tile grassTile;

    public Vector2 tileSize;

    // Start is called before the first frame update
    void Start()
    {
        InitMap();
    }
    
    private void InitMap()
    {
        tileSize =  grassTile.sprite.rect.size;
        Vector2 tmpVector = new Vector2(0, 0);

        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                //tmpVector.Set(j * tileSize.x,i*tileSize.y);
                baseTilemap.SetTile(new Vector3Int(i,j,0), grassTile);
            }
        }
        
        
    }
}
