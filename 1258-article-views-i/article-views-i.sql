# Write your MySQL query statement below
SELECT viewer_id AS id 
FROM Views 
WHERE author_id=viewer_id 
GROUP BY viewer_id ORDER BY id;