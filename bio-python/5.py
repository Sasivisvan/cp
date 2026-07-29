#bonus
#5-6 blast

#Smith-Waterman Algorithm
def local_alignment(seq1, seq2):
    # 1. Initialization
    m, n = len(seq1), len(seq2)
    
    # Scoring scheme (Simple: +3 match, -3 mismatch, -2 gap)
    match_score = 3
    mismatch_score = -3
    gap_penalty = -2
    
    # Create the matrix (filled with zeros)
    # Dimensions are (m+1) x (n+1)
    matrix = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    
    max_score = 0
    max_pos = (0, 0) # Keeps track of the highest score to start traceback

    # 2. Fill the Matrix
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # Calculate score for matching/mismatching
            score_diag = matrix[i-1][j-1] + (match_score if seq1[i-1] == seq2[j-1] else mismatch_score)
            
            # Calculate score for gaps (insertion/deletion)
            score_up   = matrix[i-1][j] + gap_penalty
            score_left = matrix[i][j-1] + gap_penalty
            
            # Local alignment rule: logic cannot go below 0
            matrix[i][j] = max(0, score_diag, score_up, score_left)
            
            # Keep track of the maximum score found so far (the "peak")
            if matrix[i][j] > max_score:
                max_score = matrix[i][j]
                max_pos = (i, j)

    # 3. Traceback (Reconstructing the path)
    align1, align2 = "", ""
    i, j = max_pos
    
    # Stop when we hit a cell with 0 (end of local alignment)
    while matrix[i][j] > 0:
        score = matrix[i][j]
        score_diag = matrix[i-1][j-1]
        score_up = matrix[i-1][j]
        score_left = matrix[i][j-1]
        
        # Check which path we came from
        if score == score_diag + (match_score if seq1[i-1] == seq2[j-1] else mismatch_score):
            align1 += seq1[i-1]
            align2 += seq2[j-1]
            i -= 1
            j -= 1
        elif score == score_up + gap_penalty:
            align1 += seq1[i-1]
            align2 += "-"
            i -= 1
        elif score == score_left + gap_penalty:
            align1 += "-"
            align2 += seq2[j-1]
            j -= 1
        else:
            break # Should not happen in this simple implementation

    # 4. Print Result (Reverse strings because we traced back)
    print("**** Local Alignment (Smith-Waterman) ****")
    print(f"Max Score: {max_score}")
    print(f"Seq1: {align1[::-1]}")
    print(f"Seq2: {align2[::-1]}")

# --- Test the code ---
# Example: Similar to a BLAST match, finding the shared 'GATTACA' region
sequence_A = "GGTTGACTA"
sequence_B = "TGTTACGG"

local_alignment(sequence_A, sequence_B)